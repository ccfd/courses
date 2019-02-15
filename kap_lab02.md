---
title: "Flow through a valve"
author: "M. Rutkowski, M.Klamka"
material: Instrukcja 2
number: 2
course: Komputerowa Analiza Przepływów/Advanced Computational Fluid Dynamics
--- 

Purpose of this laboratory is to practice the simulation of the unsteady turbulent fluid flow using the moving (rotating) mesh.

__Duration__: 2h

## Geometry and Mesh

## Fluent

1. Read the coarse mesh. **File/Read/Mesh**

2. Set the Pressure Based solver and activate Transient in **Define/General**

3. Check the scale. The mesh was created in mm.

4. Set-up the interface in **Define/Mesh Interfaces/Create Edit**. All the interfaces/interface
with the name ‘interface_1’ should be assigned to all remaining interfaces/interface
denoted by ‘interface_2’. Provide the name under Mesh Interface.

5. Activate the Spalart-Allmaras turbulence model in **Define/Models/Viscous**

6. Create a new fluid (liquid water) in **Define/Materials/Fluid/Create Edit** . Select it from
the Fluent Database.

7. Set the liquid water in all zones ‘a’, ‘b’ and ‘c’ (fig. 1) in **Define/Cell Zone**
**Conditions/Edit**. Once the liquid water is set for the one zone/face the settings can be
copied to the other zones/faces.

8. Change the angular velocity from rad/sec to rpm. **Define/Units**

9. Set the moving mesh in the motion type in **Define/Cell Zone Conditions/Edit** for the
face ‘b’ (rotating_passage). The rotational velocity could be set to 20 rpm.

10. Specify the following boundary conditions:

    * Pressure inlet: Set the Gauge Total Pressure and Supersonic/Initial Gauge

    * Pressure to 100000 Pa and the turbulent to molecular viscosity ratio to 10.
    
    * Pressure outlet: Set the turbulent to molecular viscosity ratio to 1.
    
11. Initialize the solution. **Solve/Initialization** with gauge pressure, velocity components set
to zero and the turbulent viscosity set to low values 0.01. Verify the velocity magnitude in
**Display/Graphics** and **Animations/Contours/Set up**. To adjust the view use
**Display/View/front**

12. Coming back to the **Solve/Initialization**. Chose the **Patch** button and set the pressure
equal to 100000 Pa for the zone/face ‘A’ (inlet).

13. **TUTAJ NAPISAĆ O WYSWIETLANIU**

14. Compute the force acting in x or y direction on rotating_passage. First, the density and
velocity has to be set to 1 and area to 2 under **Report/Reference value**. Next, specify the
monitoring of force in **Solve/Monitors/Create**. Activate write to console and write to file.

15. In **Solve/Run Calculation** set the time step to 0.001s and the number of time steps to 10.
Run the calculations. Next increase the number of time steps and complete the calculation
(rotate the channel by 30-45 deg).

16. Read the fine mesh and perform the computations (steps 11-15). Compare the coarse and
fine grid results.

