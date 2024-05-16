# `Philosophers` by fschuber
### I never thought philosophy would be so deadly...

![Deadlock - this is what we gotta prevent.](https://github.com/FreddyMSchubert/42_Philosophers/blob/master/assets/philos_visualization.png "Deadlock - this is what we gotta prevent.")

> The Philosophers Problem is a classic problem in computer science that illustrates issues related to resource sharing and concurrency.\
> Imagine five philosophers sitting around a table. Each philosopher alternates between thinking and eating. 🍽️💭 \
> Here’s the twist: there are only five forks, one between each pair of philosophers, and a philosopher needs both forks to eat. The challenge is to come up with a system where no philosopher starves (can't eat because the forks are always in use) and there are no deadlocks (a situation where philosophers are stuck waiting forever for forks). 😵🔄 \
> So, it’s all about balancing limited resources and ensuring smooth operations—a vital aspect of designing operating systems and concurrent programming. 🎉🔧

thanks, chatgpt!

# Installation / How to use

Clone the repo

`git clone https://github.com/FreddyMSchubert/42_Philosophers.git philosophers`

Make the projects

`cd philosophers`

`make`

Execute

`./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`
- number_of_philosophers -> amount of philosophers to test with. project is designed to handle up to ~ 200
- time_to_die -> time a philosopher will stay alive after eating (in ms)
- time_to_eat -> time it takes a philosopher to eat (in ms)
- time_to_sleep -> time it takes a philosopher to sleep (in ms)
- number_of_times_each_philosopher_must_eat -> optional parameter, many cases will run infinitely. to prevent that, each philo will count how often theyve eaten and will perish (don't think about it) once they've exceeded this number

e.g.

- `./philo 1 800 200 200` - Philosopher will not eat and will die. \
- `./philo 5 800 200 200` - No Philosopher will die. \
- `./philo 5 800 200 200 7` - No Philosopher will die and the simulation will stop when every philosopher has eaten at least 7 times. \
- `./philo 4 410 200 200` - No Philosopher will die. \
- `./philo 4 310 200 100` - One Philosopher will die.

# Approach

![Deadlock - this is what we gotta prevent.](https://github.com/FreddyMSchubert/42_Philosophers/blob/master/assets/bruh.png "Deadlock - this is what we gotta prevent.")

Granted a baseline functional setup with philos and forks not doing anything unexpected, here's the potential pitfalls:

- each philosopher holding one fork -> deadlock. if we end up here, there's no way back.
- one philo randomly taking a fork a little earlier than expected, making a neighbour starve because he needed it.

> All of this needs to happen without the philosophers beign able to communicate. They're probably too busy thinking to check whether the dude sitting right next to them is dying.

Here are the solutions I used to prevent things like that:

1. Stagger each philos initial eating time - instead of just starting out everyone trying to eat, the program starts them off staggered, creating a nice, followable pattern right from the start. This start stagger is done slightly different depending on whether the amount of philos is even or uneven.

![A Visualization of how the philosophers are staggered](https://github.com/FreddyMSchubert/42_Philosophers/blob/master/assets/vis-even.png)

2. Start off each philosopher picking up another fork first - We can use this to our advantage by having every second philosopher pick up their right fork first and every other philosopher their left fork first. This makes fork deadlocks `impossible`. Simple method, but it helped a lot!

3. Finally, I had problems with philosophers taking another hilosophers eating spot - the pattern seen in the image right about would sometimes break at random, and an unexpected philo would grab a fork, not even noticing the death of their neighbour in deep concentration!
	- To fix this, I implemented a scheduling system where each philosopher calculates their expected eating time and if the philosopher would be able to pick up a fork but is still not close to this time they will just leave the fork lie there. This fixed the problem!
	- I have not talked to anyone else who had this problem - but who cares, this philosophers implementation is now by far the most stable I've seen around.

> Those 3 ideas combined made my program run smoothly every time.

Obviously, the main part of the problem was battling helgrind and protecting everything with mutexes and handling some very hard to track down bugs. But who wants to read about that?