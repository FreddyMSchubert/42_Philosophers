# Philosophers Changelog

### v0.5.5 - 06.05.2024
- added check for whether any other philo has died to the eating check
- added step system to philo loop, now death and eat time are checked after every action
- fixed philos using the end of their eating period as the last eat time - it should be the start
- implemented fork switching mechanic - now every uneven philo takes the right, every even philo the left fork first. like this, deadlock chances are decreased

### v0.5.4 06.05.2024
- fixed single philosopher spamming sleeping and thinking endlessly because he cant eat
- added a detailed messages macro and made it print more stuff (putting forks down)
- fixed eat action not checking whether dead after locking a mutex, which could theoretically take quite some time.

### v0.5.3 - 06.05.2024
- Added printing mutex to ensure we dont print things inside of each other
- made makefile put objs in their own directory
- moved some stuff around in the structs
- added solid cleanup function
- better forks mutex array handling

---

### v0.5.2 - 02.05.2024
- multiple completely inconsequential changes
	- some of them even went so far as to change the code in any way whatsoever
- added some helpful comments where necessary
- removed submodules, they should both be unnecessary. libft isnt allowed and ft_printf is unnecessary now that weve got normal printf

### v0.5.1 - 02.05.2024
- its been a while.
- created an include folder, added colors.h for ansi color codes (had to change all header file references) & replaces previous color printouts
- added readme
- moved all imports to header for clarity & a better overview
- for some reason, there was a compilation issue - easy to fix, but makes me anxious, i dont remember how i left this code

---

## v0.5.0 - 16.01.2024
- before having philo fall asleep, program now checks whether he will starve during sleep. if so, only wait usleep that long and accurately time the death message

## v0.4.0 - 16.01.2024
- define shared flag "death" that every thread checks to signal if another thread
	died and program should end
- proper wraparound for forks of last philo, previously, it would access a non-existent fork
- added nice function for philo state logging with colors
- norminette improvements, code cleanup
- renamed struct property number_of_times_each_philosopher_must_eat to something less lengthy

---

## v0.3.0 - 15.01.2024
- added timing.c, which gets milliseconds since Jan 1, 1970
- added eating mutex functionality
- created philo loop, currently with dysfunctional exit

---

## v0.2.0 - 11.01.2024
- created setup function that inits mutexes and starts philo threads
- created simple thread function that currently just prints some thread input data
- moved printing function into own file & general cleanup
- Added epic table visualization

---

## v0.1.0 - 09.01.2024
- Added makefile, header, subject, folder structure
- created logger & atoi utils
- created an input manager that populates the new t_inputs struct
- created tester.sh to check whether everything works