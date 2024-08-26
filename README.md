# 42_-philosophers
Eat + sleep + think ==  philosophers?   
Use thread and mutex lock to handle philosopher problem (mandatory part).   
A good introduction to this problem and project: https://medium.com/@jalal92/the-dining-philosophers-7157cc05315   
The project grade is 100/100.

# **Some parts of work**   
1) Input check       ✅  
   Arguments number  ✅  
   Arguments valid   ✅   
2) Initial data      ✅    
3) Thread handle     ✅   
   Philo's action    ✅   
   Mutex handle      ✅   
   Status check      ✅   

## **Compilation**   
To compile this project you should run `make` in the terminal.    
To run the program needs to follow this:   
```sh  
$ ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]   
```   
For example: `./philo 4 410 200 200 10`  
(As the evaluation page said: Do not test with more than 200 philosophers.   
Do not test with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms.)    

## **Some tips**  
The visualize tool recommendation: https://nafuka11.github.io/philosophers-visualizer/   
   
The printer lock is really important. At least in my logic. Don't consider how to avoid a data race if doesn't have this.   
   
If you do not like to do the process work or you are not a bonus hunter, For this bonus part I do not recommend it as we probably need to use a different way(thread -> process && mutex -> semaphore) to solve the same problem. And it probably cannot improve anything (efficiency etc.).  
