STRUCT Task:
- title (char array, max 100)
- description (char array, max 200)
- priority (enum: LOW, MEDIUM, HIGH)
- due_date (char array, YYYY-MM-DD)
- completed (enum: PENDING, COMPLETE, URGENT)

FUNCTIONS:
- add_task() → asks user for description, priority, due date → adds to array
- view_tasks() → shows all tasks sorted by due date (soonest first), then priority
- mark_complete() → asks user for task ID → marks as complete
- get_status(task) → returns "COMPLETE", "URGENT", or "PENDING"

STORAGE:
- Dynamic array using malloc/realloc
- Start with capacity for 10 tasks

MENU:
1. Add Task
2. View Tasks
3. Mark Task Complete
4. Exit