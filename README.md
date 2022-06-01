<h1 align="center">
    P H I L O S O P H E R S
</h1>

___

## :memo: **About**

_In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes._

### *Keywords*  
> + Unix logic

### *Skills*
> + Unix
> + Imperative programming
> + Rigor

For detailed information, refer to the [**subject of this project**](https://github.com/cherdantsevilya/philo/blob/main/content/en.subject.pdf).

___

## 🚀 **Description**

*I’ve never thought philosophy would be so deadly 💀*

<p align="center">
  <img src="https://user-images.githubusercontent.com/40824677/137200907-21044ac4-00d4-4b10-a09e-bf01b4db15c1.png" />
</p>

### *Dining philosophers*

In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.
It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present form.

The dining philosopher's problem is the classical problem of synchronization which says that Five philosophers are sitting around a circular table and their job is to think, eat and sleep alternatively. A bowl of noodles is placed at the center of the table along with five forks for each of the philosophers. To eat a philosopher needs both their right and a left forks. A philosopher can only eat if both immediate left and right forks of the philosopher is available. In case if both immediate left and right forks of the philosopher are not available then the philosopher puts down their (either left or right) fork and starts thinking again.

### *What you need to know?*

> - [X] Threads
> - [X] Processes
> - [X] Mutex
> - [X] Semaphore
> - [X] Deadlock

### *Rules*

+ One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
+ The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
+ There are also forks on the table. There are as many forks as philosophers.
+ Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
+ When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
+ Every philosopher needs to eat and should never starve.
+ Philosophers don’t speak with each other.
+ Philosophers don’t know if another philosopher is about to die.
+ No need to say that philosophers should avoid dying!

### *Input parameters*

```c
 ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- number_of_philosophers: The number of philosophers and also the number
of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

### *Output*

*Any state change of a philosopher must be formatted as follows:*

> + timestamp_in_ms X has taken a fork
> + timestamp_in_ms X is eating
> + timestamp_in_ms X is sleeping
> + timestamp_in_ms X is thinking
> + timestamp_in_ms X died

*Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.*

___

## 🍝 **The process of philosophers' life**

<p align="center">
    <img src="https://github.com/cherdantsevilya/philo/blob/main/content/philo.gif">
</p>

___

## 📌 **Useful links**

+ [Deadlock](https://learnc.info/c/pthreads_deadlock.html)
+ [Visualizer](https://nafuka11.github.io/philosophers-visualizer/)
+ [CodeVault](https://www.youtube.com/c/CodeVault)
+ [Mutex vs Semaphore](https://www.geeksforgeeks.org/mutex-vs-semaphore/)
+ [Multithreading in C](https://www.geeksforgeeks.org/multithreading-c-2/)

