# Philosophers Changelog

### v0.6.8 - 15.05.2024
- made the fork mutexes protect a list of booleans, not be the forks themselves
- moved death.c to philo_loop folder, makes more sense
- stopped errors from not logging with VERBOSE (renamed it back, too. it also changed the changelog, which may or may not be pretty confusing)
- reworked atoi.c, ft_isspace is unnecessary, and added a check for if theres anything at all that isnt a number. if so, throw error

## v0.6.7 - 15.05.2024
- valgrind
	- fixed death flag mutex not being cleaned up in cleanup function
- helgrind also fine, lets go

### v0.6.6 - 15.05.2024
- i broke the death flag thing - now everybody dies without checking the others. FIXED! quick push, should have checked that before pushing the last commit

### v0.6.5 - 15.05.2024
- moved all shared resources from philo inputs to inputs, that was the death flag & its mutex

### v0.6.4 - 15.05.2024
- removed detailed logging functionality
- removed print_philo_input_data, its unused
- renamed VERBOSE to VERBOSE, its clearer and doesnt do anything else anyways
	- i thought that then i set VERBOSE to 0 and nothing logged. 
- norminettification, again, thats done now
- fixed logic flow issue preventing the program to start in input validation when log_error wasnt on
- currently we segfault but ill fix that later

### v0.6.3 - 15.05.2024
- death flag mutex with getters and setters so philos dont die after each other
- dedicated die method which executes both death flag getter and setter for data race safety
- added emojis to philo logging, togglable with emoji macro in header
- all tests still passed

### v0.6.2 - 10.05.2024
- fixed logic issue in previous norminettification
- clearer input error messages
- freed everything that was dynamically allocated anywhere, destroyed all the mutexes

### v0.6.1 - 10.05.2024
- norminettification
	- create log_detailed_philo_action function, more compact
	- complete restructuring of determine_first_philo_to_eat, still works
	- restructuring of philo_loop, moved logic inside of while loop to execute_philo_action
	- general refactorings

### v0.6.0 - 07.05.2024
- fixed sleep using milliseconds and microseconds inconsistently.
- added determine_first_philo_to_eat function, which ensures the first and last philo dont go on each others nerves.
- created expected eat time system
	- in think, this eat time gets calculated.
	- in eat, we wont start eating until roughly that time.
	- also, the philos get staggered differently at the start depending on how many there are in total

### v0.5.6 - 06.05.2024
- mini fixes
	- made philo loop log is thinking for the threads that dont start by eating, makes more sense
	- made thread with only one philo not wait 200 ms at start

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

## v0.5.0 - 16.01.2024
- before having philo fall asleep, program now checks whether he will starve during sleep. if so, only wait usleep that long and accurately time the death message

## v0.4.0 - 16.01.2024
- define shared flag "death" that every thread checks to signal if another thread
	died and program should end
- proper wraparound for forks of last philo, previously, it would access a non-existent fork
- added nice function for philo state logging with colors
- norminette improvements, code cleanup
- renamed struct property number_of_times_each_philosopher_must_eat to something less lengthy

## v0.3.0 - 15.01.2024
- added timing.c, which gets milliseconds since Jan 1, 1970
- added eating mutex functionality
- created philo loop, currently with dysfunctional exit

## v0.2.0 - 11.01.2024
- created setup function that inits mutexes and starts philo threads
- created simple thread function that currently just prints some thread input data
- moved printing function into own file & general cleanup
- Added epic table visualization

## v0.1.0 - 09.01.2024
- Added makefile, header, subject, folder structure
- created logger & atoi utils
- created an input manager that populates the new t_inputs struct
- created tester.sh to check whether everything works