# Philosophers Changelog

## currently unfreed mallocs
- forks
- philo inputs

## todo
- fix input parsing
	- no numbers?
	- negative handling currently bad

### v0.5.0 - 16.01.2024
- before having philo fall asleep, program now checks whether he will starve during sleep. if so, only wait usleep that long and accurately time the death message

### v0.4.0 - 16.01.2024
- define shared flag "death" that every thread checks to signal if another thread
	died and program should end
- proper wraparound for forks of last philo, previously, it would access a non-existent fork
- added nice function for philo state logging with colors
- norminette improvements, code cleanup
- renamed struct property number_of_times_each_philosopher_must_eat to something less lengthy

---

### v0.3.0 - 15.01.2024
- added timing.c, which gets milliseconds since Jan 1, 1970
- added eating mutex functionality
- created philo loop, currently with dysfunctional exit

---

### v0.2.0 - 11.01.2024
- created setup function that inits mutexes and starts philo threads
- created simple thread function that currently just prints some thread input data
- moved printing function into own file & general cleanup
- Added epic table visualization

---

### v0.1.0 - 09.01.2024
- Added makefile, header, subject, folder structure
- created logger & atoi utils
- created an input manager that populates the new t_inputs struct
- created tester.sh to check whether everything works