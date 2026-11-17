---
number: 6
course: HPC
material: Labs
author: J. Gałecki
title: Lab 6
---


# Lab VI

## Background

### What is MPI?

MPI is a standard for writing programs that run as **many independent processes**, each with its **own private memory**. Processes cooperate by **sending messages**. The same program is launched N times (the SPMD model: *Single Program, Multiple Data*), and each copy behaves differently depending on its **rank**.

```
        mpirun -np 4 ./program

 ┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐
 │ rank 0  │  │ rank 1  │  │ rank 2  │  │ rank 3  │
 │ own mem │  │ own mem │  │ own mem │  │ own mem │
 └────┬────┘  └────┬────┘  └────┬────┘  └────┬────┘
      └────────────┴─── messages ──┴────────────┘
```

> **Key difference from multithreading (TBB):** processes do *not* share variables. If rank 0 changes `x`, rank 1 does not see it unless a message is sent.

### The essential vocabulary

| Term | Meaning |
|------|---------|
| **Communicator** | A group of processes that can talk to each other. `MPI_COMM_WORLD` contains all of them. |
| **Size** | Number of processes in a communicator. |
| **Rank** | Unique ID of a process, from `0` to `size-1`. |
| **Tag** | An integer label attached to a message, used to match sends with receives. |

### The 6 calls you will use all the time

```c
MPI_Init(&argc, &argv);                 // start MPI
MPI_Comm_size(MPI_COMM_WORLD, &size);   // how many processes?
MPI_Comm_rank(MPI_COMM_WORLD, &rank);   // who am I?
MPI_Send(buf, count, type, dest, tag, comm);
MPI_Recv(buf, count, type, source, tag, comm, &status);
MPI_Finalize();                         // stop MPI
```

Common datatypes: `MPI_INT`, `MPI_DOUBLE`, `MPI_CHAR`.

---

## Setup

### Install MPI using Spack

Every time you open a new terminal session, load Spack shell support:

```bash
. /your/path/to/spack/share/spack/setup-env.sh
```

Install and load:

```bash
spack install openmpi  # may take a while
spack load openmpi
```

`spack load` must be repeated in every new terminal session.

### Verify

```bash
which mpicc mpirun
mpicc --version
mpirun --version
```

Both `mpicc` and `mpirun` should point to paths inside your Spack installation.

### Compile and run (cheat sheet)

```bash
mpicc program.c -o program      # compile (wrapper around gcc)
mpirun -np 4 ./program          # run with 4 processes
```

> **Tip:** If you get *"not enough slots available"* on a machine with few cores, add `--oversubscribe`:
> `mpirun --oversubscribe -np 8 ./program`

## Exercises

### Exercise 1: Hello, World (rank and size)

Run your first MPI program:

Create `hello.c`:

```c
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello from rank %d of %d\n", rank, size);

    MPI_Finalize();
    return 0;
}
```

**Tasks**

1. Compile it and run with `-np 1`, `-np 2`, `-np 4`.
2. Run the 4-process version **several times**. Is the output order always the same?
3. Modify the program so that **only rank 0** prints `"I am the boss of N processes"`, and all other ranks print `"I am a worker"`.

**Questions**

- Why is the output order not deterministic?
- What happens if you remove `MPI_Finalize()`?

---

### Exercise 2: Point-to-point messages (Send / Recv)

Pass data from one process to another.

Create `sendrecv.c`:

```c
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        int value = 42;
        MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Rank 0 sent %d to rank 1\n", value);
    } else if (rank == 1) {
        int value;
        MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Rank 1 received %d from rank 0\n", value);
    }

    MPI_Finalize();
    return 0;
}
```

**Tasks**

1. Run with `-np 2`. Then run with `-np 4`. Do ranks 2 and 3 do anything?
2. **Ping-pong:** extend the program so rank 1 adds `1` to the received value and sends it **back** to rank 0, which prints it.
3. **Ring:** write `ring.c` where rank `r` sends a number to rank `(r+1) % size`, and receives from rank `(r-1+size) % size`. Start with rank 0 sending the value `0`; each rank adds its own rank number before forwarding. Rank 0 prints the final sum when the token returns.
   - Expected result for `-np 4`: `0+1+2+3 = 6`.

> **Hint for the ring:** rank 0 must **send first, then receive**; all other ranks must **receive first, then send**. Otherwise all processes wait for each other forever.

**Questions**

- What is a *deadlock*? Make one on purpose: have both rank 0 and rank 1 call `MPI_Recv` first. What happens?
- What do the `dest`, `source`, and `tag` arguments do?

---

### Exercise 3: Collective communication: Broadcast and Reduce

Use operations that involve **all** processes at once.

| Call | What it does |
|------|--------------|
| `MPI_Bcast` | One process sends the same data to everyone. |
| `MPI_Reduce` | Combine values from everyone (sum, max, ...) into one process. |
| `MPI_Scatter` | Split an array from one process into pieces, one per process. |
| `MPI_Gather` | Collect pieces from everyone into one array on one process. |

Since arctan(1) = π/4, the integral of 4/(1+x²) from 0 to 1 equals exactly π:

$$\pi = \int_0^1 \frac{4}{1+x^2}\,dx \;\approx\; h \sum_{i=0}^{n-1} \frac{4}{1+x_i^2}, \qquad h = \frac{1}{n}, \quad x_i = h\,(i + 0.5)$$

We approximate the area under the curve with `n` thin rectangles of width `h`, using the midpoint `x_i` of each interval as its height. The more rectangles, the better the estimate. The work parallelizes naturally: each rank sums its own share of the rectangles (every `size`-th one), and `MPI_Reduce` adds the partial sums.

Create `pi.c`:

```c
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    long n = 0;
    if (rank == 0) n = 100000000;                     // number of intervals
    MPI_Bcast(&n, 1, MPI_LONG, 0, MPI_COMM_WORLD);    // everyone gets n

    double h = 1.0 / n, local_sum = 0.0;
    for (long i = rank; i < n; i += size) {           // each rank takes every size-th interval
        double x = h * (i + 0.5);
        local_sum += 4.0 / (1.0 + x * x);
    }
    local_sum *= h;

    double pi = 0.0;
    MPI_Reduce(&local_sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) printf("pi ≈ %.12f\n", pi);

    MPI_Finalize();
    return 0;
}
```

**Tasks**

1. Compile and run with 1, 2, 4 processes. Is the result the same?
2. Change `MPI_SUM` to `MPI_MAX`. What does the program print now, and why?
3. Replace `MPI_Reduce` by `MPI_Allreduce` (no `root` argument) and make **every** rank print the result.

**Questions**

- Why do we broadcast `n` instead of letting every rank set it?
- Why is `MPI_Reduce` better than having every rank `MPI_Send` to rank 0 manually?

---

### Exercise 4: Scatter and Gather: parallel array sum

Distribute data, compute locally, collect results.

Create `scatter.c`:

```c
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define PER_PROC 5

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *data = NULL;
    if (rank == 0) {                                   // only root owns the full array
        data = malloc(size * PER_PROC * sizeof(int));
        for (int i = 0; i < size * PER_PROC; i++) data[i] = i + 1;
    }

    int local[PER_PROC];
    MPI_Scatter(data, PER_PROC, MPI_INT,
                local, PER_PROC, MPI_INT, 0, MPI_COMM_WORLD);

    int local_sum = 0;
    for (int i = 0; i < PER_PROC; i++) local_sum += local[i];
    printf("Rank %d: local sum = %d\n", rank, local_sum);

    int *sums = NULL;
    if (rank == 0) sums = malloc(size * sizeof(int));
    MPI_Gather(&local_sum, 1, MPI_INT, sums, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        int total = 0;
        for (int i = 0; i < size; i++) total += sums[i];
        printf("Total = %d\n", total);
        free(data); free(sums);
    }

    MPI_Finalize();
    return 0;
}
```

**Tasks**

1. Run with `-np 4`. Verify by hand that the total equals `1+2+...+20 = 210`.
2. Compute the **average** of the whole array instead of the sum (use `double`).
3. Find the **global maximum** using `MPI_Reduce` with `MPI_MAX` instead of `MPI_Gather`.

**Questions**

- What does the `sendcount` argument of `MPI_Scatter` mean: the total array size, or the size of *one piece*?
- What would you do if the array length was **not** divisible by the number of processes? (Look up `MPI_Scatterv`.)

---

### Exercise 5: Non-blocking communication

Start a communication, keep working, and wait for it to finish later.

`MPI_Send` and `MPI_Recv` are **blocking**: the call returns only when it is safe to reuse the buffer (for `MPI_Recv`, when the data has arrived). Their **non-blocking** counterparts return immediately and give you a *request* handle:

| Call | What it does |
|------|--------------|
| `MPI_Isend(buf, count, type, dest, tag, comm, &req)` | Start sending, return at once. |
| `MPI_Irecv(buf, count, type, source, tag, comm, &req)` | Start receiving, return at once. |
| `MPI_Wait(&req, &status)` | Block until one operation is complete. |
| `MPI_Waitall(n, reqs, statuses)` | Block until all `n` operations are complete. |

> **Important:** do not touch the buffer of a pending `Isend`/`Irecv` until the matching `Wait` has returned. Reading a receive buffer too early gives garbage; modifying a send buffer too early may corrupt the message.

Because nothing blocks while posting, **every rank can post its receive and its send without worrying about order**. This removes the "rank 0 sends first, everyone else receives first" trick from Exercise 2.

Create `nonblocking_ring.c`:

```c
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int right = (rank + 1) % size;          // neighbour to send to
    int left  = (rank - 1 + size) % size;   // neighbour to receive from

    int send_val = rank * 10;
    int recv_val = -1;
    MPI_Request reqs[2];

    MPI_Irecv(&recv_val, 1, MPI_INT, left,  0, MPI_COMM_WORLD, &reqs[0]);
    MPI_Isend(&send_val, 1, MPI_INT, right, 0, MPI_COMM_WORLD, &reqs[1]);

    // Independent computation could go here...

    MPI_Waitall(2, reqs, MPI_STATUSES_IGNORE);

    printf("Rank %d received %d from rank %d\n", rank, recv_val, left);

    MPI_Finalize();
    return 0;
}
```

**Tasks**

1. Compile and run with `-np 4`. Check that rank `r` receives `((r-1+4) % 4) * 10`.
2. **Show why it is safe:** write a blocking version in which *every* rank calls `MPI_Send` to its right neighbour and then `MPI_Recv` from its left neighbour. Run it with `-np 4`. It may work or hang (small messages are often buffered by MPI), so try increasing the message to an array of 1,000,000 `int`s. Compare with the non-blocking version using the same array size.
3. **Overlap communication and computation:** in the non-blocking version, between the `Isend`/`Irecv` calls and `MPI_Waitall`, add a loop that does some work *not* involving `send_val` or `recv_val`, for example summing the numbers `0..10^8`.
4. **Move the Wait too early:** print `recv_val` *before* `MPI_Waitall`. What do you observe? Run it a few times.

**Questions**

- Why is it incorrect to read `recv_val` before `MPI_Waitall`?
- When can overlapping communication and computation give a real speedup? (Think about message size and how much independent work you have.)
- What is the difference between `MPI_Wait` and `MPI_Waitall`?

---

## Bonus Challenges

1. **Parallel Monte Carlo π:** each rank throws random points into the unit square (use `srand(rank + 1)`), counts hits inside the quarter circle, and `MPI_Reduce` sums the counts.
2. **Matrix–vector multiplication:** scatter rows of a matrix, broadcast the vector, gather the result.
