# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflection

### Effect of P

P stands for proportional and steers the car in proportion to the cross-track error. By itself, a proportional controller will always overshoot its goal and never really converges. For the proportional constant I arrived at 0.55. Honestly, I didn't have a strong expectation for this value and it required a lot of manual tuning to better understand an appropriate value (see 'Choosing Hyperparameters').

### Effect of I

The I effect - or integral - allows the steering to adjust for the bias of the car. To measure this integral effect, we take the sum of the cross track error over time and adjust the steering proportionally. For the proportional constant I arrived at 0.00000755. This is close to what I would have expected because my prior was a small amount of bias in our simulated car.

### Effect of D

To help avoid the over shotting and oscillation of the P controller, the D - or derivative - effect is added. This steers the car in proportion to the temporal derivative of the cross-track error, allowing a counter steer as we approach our goal. For the proportional constant I arrived at 11.55. Again, for D, I also didn't have a strong expectation, though I somewhat expected it to be larger than P to allow for a smoother convergence to the goal. 

### Choosing hyperparameters

I arrived at my hyperparameters via a manual grid search. I started my search around (1, .0001, 5). The P and D values were fairly arbitrary, but I chose a low I value because I believed there would be small car bias. I then would altered each by a magnitude of +-1 to see if it improved the steering. Once, I got within a value of 1, I moved by 0.11 intervals. 

I quickly discovered, though, that I needed a much smaller I value due to too much over correction over time. So I quickly jumped down magnitudes to .000005 and made smaller tunes from there. 

This process took longer that I would have first imagined, so at some point I may go back and try to implement twiddle. It would be interesting to see how quickly it finds appropriate values.
