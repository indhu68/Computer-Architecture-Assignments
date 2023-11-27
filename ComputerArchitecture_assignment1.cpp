
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
class Event {
public:
 Event(int event_no, int time, int value) : Event_no(event_no), t(time), v(value) {}
 int getEventNo() const {
 return Event_no;
 }
 int getTime() const {
 return t;
 }
 int getValue() const {
 return v;
 }
 Event generatingNewEvent() const {
 return Event(Event_no + 1, t + rand() % v, rand() % 1000);
 }
private:
 int Event_no;
 int t;
 int v;
};
bool comparingByTime(const Event& e1, const Event& e2) {
 if (e1.getTime() != e2.getTime()) {
 return e1.getTime() < e2.getTime();
 }
 return e1.getValue() < e2.getValue();
}
int main() {
 srand(time(nullptr)); // Random generator is seeded
 vector<Event> E;
 int eventNoCounter = 1; // Event_no counter is initialized
 generate_n(back_inserter(E), 20, [&eventNoCounter]() {
 return Event(eventNoCounter++, rand() % 1000, rand() % 1000);
 });
 // Sort events by time
 sort(E.begin(), E.end(), comparingByTime);
 // Event numbers in ascending order
 for (int i = 0; i < E.size(); i++) {
 E[i] = Event(i + 1, E[i].getTime(), E[i].getValue());
 }
 // Print the sorted Events and Event numbers in ascending order
 for (const Event& e : E) {
 cout << "Event no: " << e.getEventNo() << " -> " << " time: " << e.getTime() << ", value: " <<
e.getValue() << "\n";
 }
 // Read the earliest event, print the value, and generate a new event
 Event oldEvent = E.front();
 cout << "Earliest Event's time and value : " << "time: " << oldEvent.getTime() << " value: " <<
oldEvent.getValue() << "\n";
 Event newEvent = oldEvent.generatingNewEvent();
 // Process new Events E' up to 100 event numbers
 while (E.size() < 100) {
 oldEvent = E.front();
 newEvent = oldEvent.generatingNewEvent();
 // Insert the new Event E' into the sorted vector
 auto insertPosition = upper_bound(E.begin(), E.end(), newEvent, comparingByTime);
 E.insert(insertPosition, newEvent);
 // After insertion, reassign Event_no in ascending order
 for (int i = 0; i < E.size(); i++) {
 E[i] = Event(i + 1, E[i].getTime(), E[i].getValue());
 }


 }
 // After insertion and reassignment, print the new events E'
 cout << "New Events:\n";
 for (const Event& e : E) {
 cout << "New Event no: " << e.getEventNo() << " -> " << " time: " << e.getTime() << ", value: " <<
e.getValue() << "\n";
 }
 return 0;
 }
