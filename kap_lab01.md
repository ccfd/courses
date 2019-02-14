---
title: "Flow over and airflow"
author: "M. Rutkowski, M.Klamka"
material: Instrukcja 1
number: 1
course: Komputerowa Analiza Przepływów/Advanced Computational Fluid Dynamics
--- 

Purpose of this laboratory is to practice a generation of block-structured mesh and perform a simulation of steady turbulent fluid flow over NACA0012 profile at angle of attack set to $1.55^{\circ}$ and freestream Mach number 0.7.

__Duration__: 2h

##Geometry and Mesh

1. Open Workbench 14 (Start Menu/Programy/ANSYS 14...). Drag and drop the **Geometry**
component system into the **Project Schematic**. Open the **Geometry** cell. Make a
NACA0012 profile using the text ASCII file [naca0012-3d-curve.txt](data/KAP/naca0012-3d-curve.txt): Open Design
Modeler. Specify m as unit of length. Select **Concept/3d-Curve**. Provide a link to above
file under **Coordinates File**. Click on **Generate** button.


![Final block-structured mesh](figures/KAP/Lab1_mesh.png "Final block-structured mesh")

##Fluent

1. Read the mesh file. Check the scale. Keep the length in m. Rotate the mesh by 1.55 deg.
**Mesh/Rotate/** set -1.55 deg.

2. Set-up the computations in Fluent. The inlet Mach (M) number is $0.7$, the Reynolds
number based on chord length of the airfoil and inlet velocity is $1.5 \cdot 10^{6}$ . Change the
fluid viscosity to specify the proper Reynolds number.

3. Select appropriate turbulence model (Spalart-Allmaras or SST k-omega) and specify the
boundary conditions on pressure far field boundary. The numerical results will be
compared with experiment performed at conditions $p_{0} = 101325 Pa$ , $T_{0}=311 K$. The static
pressure and static temperature has to be specified in the boundary condition tab.

    * Set the operating pressure to $0 Pa$ **Define/Boundary Conditions/Operating Condition**.

    * Set the static pressure to $73048 Pa$ (**Define/Boundary Conditions/pressure far field**).
    \[\frac{p_{0}}{p} = \left[ 1 +\left(\frac{\gamma - 1}{2}\right) M^{2}\right]^{\frac{\gamma}{\gamma - 1}} \]
    
    * Set the static temperature to $283 K$. For air $\gamma=1.4$.
    \[\frac{T_{0}}{T} =  1 +\left(\frac{\gamma - 1}{2}\right) M^{2}\ \]
    
    *Turbulence quantities. Ratio of turbulent to molecular viscosity $\nu = 10$, Turbulent intensity $TI = 1%$.

4. Run the computations. The residuals should fall down below $10^{-5}$. The numerical scheme
should be set to the second order upwind.

5. Verify the pressure, temperature and velocity fields. Verify the lift and drag coefficients
cd=Fd/(0.5 u2 A)
\[c_{d} =  \frac{F_{D}}{0.5 \rho u^{2} A} \]
, (A is equal to 1) and compare them with literature data (activate the
freestream conditions in **Report/Reference values**). For this flow the measured lift and
drag coefficient are equal to $c_{l}=0.241$, $c_{d}=0.0079$. Note that the forces have to be
computed with respect to direction of the incoming flow. This is why the mesh has been
rotated in the beginning by 1.55 deg. It means that the lift and drag coefficients can now
easily be obtained in **Report/Forces/Direction vector** by setting 1 and 0 factors under
Direction vector. x=1 y=0 for drag, x=0, y=1 for lift.

6. Compare the measured and computed pressure coefficient profiles. **Display/Plots/XY Plot**.
The experimental profiles are stored in files: test-data-top.xy and test-data-bottom.xy
(**Load File** under **File Data**)



