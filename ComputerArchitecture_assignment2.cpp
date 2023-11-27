#include <iostream>
#include <string>
#include <vector>
using namespace std;
//4 stages of pipeline
struct InstructionCycle {
string instruction;
string n_instruction;
string mem;
string wb;
};
struct ProcessorState {
int x1 = 160;
int x2 = 0;
int clockCycle = 0;
};
void printAndPushEvent(ProcessorState& state, std::vector<std::string>& eventList, const InstructionCycle& cycle) {
string event = cycle.instruction;
if(cycle.n_instruction != "No_Op") event += " " + cycle.n_instruction;
eventList.push_back(event);
cout << "Clock Cycle " << state.clockCycle << " " << cycle.instruction << " " << cycle.n_instruction << " " << cycle.mem << " " << cycle.wb << " Value: " << state.x1 << "\n";
}
void executeCycle(ProcessorState& state, std::vector<std::string>& eventList, const std::string& instruction, const std::string& n_instruction) {
state.clockCycle++;
printAndPushEvent(state, eventList, {instruction, "No_Op", "No_Op", "No_Op"});
state.clockCycle++;
printAndPushEvent(state, eventList, {n_instruction, instruction, "No_Op", "No_Op"});
state.clockCycle++;
printAndPushEvent(state, eventList, {n_instruction, "No_Op", instruction, "No_Op"});
state.clockCycle++;
if (instruction == "addi") state.x1 = state.x1 - 8;
printAndPushEvent(state, eventList, {n_instruction, "No_Op", "No_Op", instruction});
}
void executeBneCycle(ProcessorState& state, std::vector<std::string>& eventList, std::string& l) {
state.clockCycle++; printAndPushEvent(state, eventList, {"bne", "No_Op", "No_Op", "No_Op"});
state.clockCycle++; printAndPushEvent(state, eventList, {l, "bne", "No_Op", "No_Op"});
state.clockCycle++; printAndPushEvent(state, eventList, {l, "No_Op", "bne", "No_Op"});
state.clockCycle++; printAndPushEvent(state, eventList, {l, "No_Op", "No_Op", "bne"});
}
int main() {
string instructions[] = {"load", "add", "sd", "addi", "bne"}; //instructions queue
ProcessorState state;
vector<std::string> eventList;
string l = " load ";
cout<< "\t "<<"Fetch "<<"Decode "<<"Execute "<<"Store \n";
while (state.x1 != state.x2) {
int i = 0;
while (i < 4) {
executeCycle(state, eventList, instructions[i], instructions[i + 1]);
i++;
}
state.clockCycle++;
eventList.push_back("halt");
cout << "Clock Cycle " << state.clockCycle << " halt \n";
executeBneCycle(state, eventList, l);
if (state.x1 == state.x2) {
l = " N/A ";
}
}
int cycle = 0;
while (cycle < eventList.size()) {
cout << "Event List for Clock Cycle " << cycle + 1 << ": " << eventList[cycle] << "\n";
cycle++;
}
return 0;
}
