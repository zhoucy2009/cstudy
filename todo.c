#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 256
#define INITIAL_CAPACITY 2

typedef struct {
  int id;
  char description[MAX_DESCRIPTION_LENGTH];
  bool completed;
} ToDoItem;

ToDoItem *todo_list = NULL;
int todo_count = 0;
int todo_capacity = 0;
int next_id = 1;
void initialize_todo_list() {
  todo_capacity = INITIAL_CAPACITY;
  todo_list = (ToDoItem *)malloc(sizeof(ToDoItem) * todo_capacity);
  if (todo_list == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  };

  todo_count = 0;
  next_id = 1;
}

void ensure_capacity() {
  if (todo_count >= todo_capacity) {
    todo_capacity *= 2;
    ToDoItem *temp =
        (ToDoItem *)realloc(todo_list, sizeof(ToDoItem) * todo_capacity);
    if (temp == NULL) {
      printf("Memory reallocation failed\n");
      exit(EXIT_FAILURE);
    }

    todo_list = temp;
    printf("Info:resized todo list to capacity %d\n", todo_capacity);
  }
}
void free_todo_list() {
  if (todo_list != NULL) {
    free(todo_list);
    todo_list = NULL;
  }

  todo_count = 0;
}

void add_todo(const char *description) {
  if (strlen(description) == 0) {
    printf("error: description cannot be empty\n");
    return;
  }

  ensure_capacity();

  todo_list[todo_count].id = next_id++;
  strcpy(todo_list[todo_count].description, description);
  todo_list[todo_count].completed = false;

  printf("Description added successfully : ID %d - \"%s\"\n",
         todo_list[todo_count].id, todo_list[todo_count].description);

  todo_count++;
}

void list_todos() {
  if (todo_count == 0) {
    printf("The to do list is empty.\n");
    return;
  }

  printf("\n---Current To-Dos(%d items)---\n", todo_count);
  for (int i = 0; i < todo_count; i++) {
    printf("ID:%d | Description: %s | Status: %s\n", todo_list[i].id,
           todo_list[i].description,
           todo_list[i].completed ? "Completed" : "Pending");
  }
  printf("---------------------------\n");
}

void complete_todo(int id) {
  for (int i = 0; i < todo_count; i++) {
    if (todo_list[i].id == id) {
      if (todo_list[i].completed) {
        printf("Info:To-Do item with ID %d is already completed.\n", id);
      } else {
        todo_list[i].completed = true;
        printf("Success:To-Do item with ID %d marked as completed.\n", id);
      }
      return;
    }
  }
  printf("Error:To-Do item with ID %d not found.\n", id);
}

void delete_todo(int id) {
  int found_index = -1;
  for (int i = 0; i < todo_count; i++) {
    if (todo_list[i].id == id) {
      found_index = i;
      break;
    }
  }
  if (found_index != -1) {
    for (int i = found_index; i < todo_count - 1; i++) {
      todo_list[i] = todo_list[i + 1];
    }
    todo_count--;
    printf("Success:To-Do item with ID %d deleted.\n", id);
  } else {
    printf("Error:To-Do item with ID %d not found.\n", id);
  }
}

void save_todos_to_file(const char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error:Could not open file %s for writing.\n", filename);
    return;
  }

  for (int i = 0; i < todo_count; i++) {
    fprintf(file, "%d|%s|%d\n", todo_list[i].id, todo_list[i].description,
            todo_list[i].completed);
  }

  fclose(file);
}
int main(void) {

  initialize_todo_list();
  int choice;
  char temp_description[MAX_DESCRIPTION_LENGTH];
  int temp_id;

  do {
    // Display menu
    printf("\n---To-Do List Menu---\n");
    printf("1.Add To-Do Item\n");
    printf("2.List To-Dos\n");
    printf("3.Mark To-Do as Completed\n");
    printf("4.Delete To-Dos\n");
    printf("5.Save To-Dos\n");
    printf("6.Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid input.Please enter a number.\n");
      while (getchar() != '\n')
        ;
      continue; // skip to next iteration
    }

    // consume left over newline character
    while (getchar() != '\n')
      ;

    switch (choice) {
    case 1:
      printf("Enter a new todo description:");
      fgets(temp_description, sizeof(temp_description), stdin);
      temp_description[strcspn(temp_description, "\n")] = '\0';
      add_todo(temp_description);
      break;
    case 2:
      list_todos();
      break;
    case 3:
      list_todos();
      printf("Enter the ID of the todo to mark as completed:");
      if (scanf("%d", &temp_id) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
          ;
        continue;
      }

      while (getchar() != '\n')
        ;
      complete_todo(temp_id);
      break;
    case 4:
      list_todos();
      printf("Enther the ID of the todo to delete:");
      if (scanf("%d", &temp_id) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
          ;
        continue;
      }
      while (getchar() != '\n')
        ;
      delete_todo(temp_id);
      break;
    case 5:
      save_todos_to_file("todos.txt");
      printf("To-Dos saved to todos.txt successfully.\n");
      break;

    case 6:
      printf("Exiting program. Goodbye!\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 6);

  free_todo_list();

  return 0;
}