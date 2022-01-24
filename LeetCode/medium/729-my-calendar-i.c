#include "_leetcode_common.h"

#define MAX_SIZE 1000

typedef struct {
  int *starts;
  int *ends;
  int size;
} MyCalendar;

MyCalendar *myCalendarCreate() {
  MyCalendar *c = (MyCalendar *) malloc(sizeof(MyCalendar));
  c->starts = (int *) malloc(sizeof(int) * MAX_SIZE);
  c->ends = (int *) malloc(sizeof(int) * MAX_SIZE);
  c->size = 0;
  return c;
}

bool myCalendarBook(MyCalendar *obj, int start, int end) {
  if (end <= start) {
    return false;
  }

  for (int i = 0; i < obj->size; ++i) {
    if (end > obj->starts[i] && obj->ends[i] > start) {
      return false;
    }
  }

  obj->starts[obj->size] = start;
  obj->ends[obj->size] = end;
  ++obj->size;
  return true;
}

void myCalendarFree(MyCalendar *obj) {
  free(obj->starts);
  free(obj->ends);
  free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);

 * myCalendarFree(obj);
*/
int main(int argc, char *argv[]) {
  MyCalendar *obj = myCalendarCreate();

  printf("%d\n", myCalendarBook(obj, 10, 20));
  printf("%d\n", myCalendarBook(obj, 15, 25));
  printf("%d\n", myCalendarBook(obj, 20, 30));

  myCalendarFree(obj);

  return 0;
}
