#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
  char name[100];
  int completed;
};

struct TaskList {
  struct Task tasks[MAX_TASKS];
  int num_tasks;
};

void init_task_list(struct TaskList *list) {
  list->num_tasks = 0;
}

void add_task(struct TaskList *list, char *name) {
  if (list->num_tasks == MAX_TASKS) {
    printf("Error: Task list is full.\n");
    return;
  }
  strcpy(list->tasks[list->num_tasks].name, name);
  list->tasks[list->num_tasks].completed = 0;
  list->num_tasks++;
}

void mark_task_complete(struct TaskList *list, int task_index) {
  if (task_index < 0 || task_index >= list->num_tasks) {
    printf("Error: Invalid task index.\n");
    return;
  }
  list->tasks[task_index].completed = 1;
}

void remove_task(struct TaskList *list, int task_index) {
  if (task_index < 0 || task_index >= list->num_tasks) {
    printf("Error: Invalid task index.\n");
    return;
  }
  for (int i = task_index; i < list->num_tasks - 1; i++) {
    list->tasks[i] = list->tasks[i + 1];
  }
  list->num_tasks--;
}

void print_task_list(struct TaskList *list) {
  printf("To-do list:\n");
  for (int i = 0; i < list->num_tasks; i++) {
    printf("%d. %s %s\n", i + 1, list->tasks[i].name,
           list->tasks[i].com
