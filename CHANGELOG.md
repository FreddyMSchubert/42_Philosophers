# Philosophers Changelog

## currently unfreed mallocs
- forks
- threads
- philo inputs

## todo
- fix input parsing
	- no numbers?
	- negative handling currently bad
- define shared flag "death" that every thread checks

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