# DevLog1 23/03/26

Been a moment since I have had some time to sit down and do some work on this project, I thought I would start these Development Logs as a way to track my progress and also as a way to track things I have learnt and what I am developing within my simulator, as I started this project to learn more about Gravity and Orbital Dynamics between diffrent Objects.

At the moment i have:

- A Rather simple little simulator that takes two obejcts(Earth and A Spaceship for now)
- Calculates the Gravitational Acceleration between the two objects using Newton's Law of Universal Gravitation (F = GMm/r²)
- Applies the acceleration to the spaceship and updates its position accordingly.


At the moment the values are just hardcoded as I was testing the functionality which means that the Spaceship does just crash towards earth at the moment...which is not ideal, but before I play around wiht adding velocity to the Spaceship I want to add some sort of rending so I can see Earth and my spaceship start to orbit eachother and be drawn in realtime, I think SFML for a 2D render at first before moving to an OpenGL 3D render would be a good start.