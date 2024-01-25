#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void showTasks(const vector<string> &tasks)
{
    cout<<"To do list: "<<endl;
    for(int i = 0; i < tasks.size(); i++)
    {
        cout<<i + 1<<". "<<tasks[i]<<endl;
    }
}

void addTask(string new_task, vector<string> &tasks)
{
    tasks.push_back(new_task);
}

int main()
{
    vector<string> tasks;
    string task;
    string new_task;
    char choice;


    //retrieve the file:
    ifstream inputfile("tasks.txt");
    while(getline(inputfile, task))
    {
        tasks.push_back(task);
    }
    inputfile.close();

    //choices:
    do
    {
        cout<<"Enter a choice"<<endl;
        cout<<"A - Add task"<<endl;
        cout<<"V - View tasks"<<endl;
        cout<<"Q - Quit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 'A':
            case 'a':
                cout<<"Enter a task"<<endl;
                cin>>new_task;
                addTask(new_task, tasks);
                break;

            case 'V':
            case 'v':
                showTasks(tasks);
                break;
        }
    } while (choice !='Q' && choice!='q');
    
    //saving the choices:
    ofstream outputfile("tasks.txt");
    for(const auto &t: tasks) //for(task in tasks)
    {
        outputfile << t << endl;
    }
    outputfile.close();

    return 0;
}