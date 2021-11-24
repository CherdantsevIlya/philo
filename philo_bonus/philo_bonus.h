#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct	s_philo
{
	t_data		*data;
	int			name;
	char		*sem_name;
	int			num_of_eat;
	long long	start_eat_time;
	sem_t		*death;
	pid_t		pid;
};

struct	s_data
{
	t_philo		*philo;
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_must_eat;
	sem_t 		*forks;
	sem_t		*print;
	sem_t		*death_flag;
	sem_t		*count_eat;
	long long	start_time;
};

void		threads(t_data *data, int argc);
void		*start_routine(void *thread);
void		*death_routine(void *thread);
void		*eat_routine(void *thread);

int			init_philo(t_data *data); // отлично
int			init_semaphore(t_data *data); // отлично
int			parsing(t_data *data, int argc, char **argv); // отлично
int			ft_atoi(const char *str); // отлчно

void		philo_takes_forks(t_philo *philo); // отлично
void		philo_eating(t_philo *philo); // думаю, что отлично, но если и
// нет, то траблы явно с 27ой строкой
void		philo_sleeping(t_philo *philo); // отлично
void		philo_thinking(t_philo *philo); // отлично

void		free_data(t_data *data, int n); // НЕТ!
void		philo_time_to(int time); // отлично
long long	now(void); // отлично

char		*ft_strjoin(char *s1, char *s2); // отлично
char		*ft_itoa(int n); // отлично
size_t		ft_strlen(const char *s); // отлично

#endif
