#include <iostream>
#include <fstream>

void printMenu();

int listTasks(std::string taskFilePath);

bool fileIsEmpty(std::ifstream &pFile);

int tasksFileNotFound();

int addTask(const std::string& taskFilePath, const std::string& taskDescription);

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printMenu();
        return 2;
    }

    std::string taskFilePath = "../tasks";
    std::string commandArg = std::string(argv[1]);

    if (commandArg == "-l") {
        return listTasks(taskFilePath);
    } else if (commandArg == "-a") {
        return addTask(taskFilePath, std::string(argv[2]));
    } else if (commandArg == "-r") {
        //TODO
    } else if (commandArg == "-c") {
        //TODO
    }

    return 0;
}



void printMenu()
{
    std::cout << std::endl;
    std::cout << "Command Line Todo application" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << std::endl;
    std::cout << "Command line arguments:" << std::endl;
    std::cout << "    -l   Lists all the tasks" << std::endl;
    std::cout << "    -a   Adds a new task" << std::endl;
    std::cout << "    -r   Removes a task" << std::endl;
    std::cout << "    -c   Completes a task" << std::endl;
    std::cout << std::endl;
}

int listTasks(std::string taskFilePath)
{
    std::ifstream taskFile(taskFilePath);
    std::string line;
    int lineCount = 1;
    std::cout << std::endl;
    if (taskFile.is_open()) {
        if (fileIsEmpty(taskFile)) {
            std::cout << "No todos for today! :)" << std::endl;
        } else {
            while (getline(taskFile, line)) {
                std::cout << lineCount << " - " << line << '\n';
                lineCount++;
            }
        }
        taskFile.close();
    } else {
        return tasksFileNotFound();
    }
    return 0;
}

int addTask(const std::string& taskFilePath, const std::string& taskDescription)
{
    std::ofstream taskFile(taskFilePath, std::ios::app);
    std::cout << std::endl;
    if (taskFile.is_open()) {
        taskFile << taskDescription << std::endl;
        taskFile.close();
    } else {
        return tasksFileNotFound();
    }
    std::cout << "New task added: " << taskDescription << std::endl;
    std::cout << std::endl;
    return 0;
}

bool fileIsEmpty(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

int tasksFileNotFound()
{
    std::cout << "Tasks file does not exist! Exiting program." << std::endl;
    return 1;
}