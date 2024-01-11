# setup

- make a bunch of philos, pass them in a phid (philo id) and a list of fork bools and corresponding mutexes

# run
gets in: basic input data, fork + mutexes list
- to start off, every second philo starts eating and all the other ones start thinking
- each philo picks fork with same phid and +1, if thats philo amount, loop back to 0
- then that just loops until we exceeded numberoftimeseachphilomusteat or he dies