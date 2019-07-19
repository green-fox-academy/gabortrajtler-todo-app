#include <iostream>
#include <fstream>

void printMenu();
void listTasks(std::string taskFilePath);

int main(int argc, char* argv[])
{
    if (argc == 1) {
        printMenu();
        return 2;
    }

    std::string taskFilePath = "../tasks";
    std::string commandArg = std::string(argv[1]);

    if(commandArg == "-l"){
        listTasks(taskFilePath);
    } else if (commandArg == "-a") {
        //TODO
    } else if (commandArg == "-r") {
        //TODO
    } else if (commandArg == "-c") {
        //TODO
    }

    return 0;
}

void printMenu() {
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

void listTasks(std::string taskFilePath) {
    std::ifstream taskFile(taskFilePath);
    std::string line;
    int lineCount = 1;
    std::cout << std::endl;
    if (taskFile.is_open()) {
        while (getline(taskFile, line)) {
            std::cout << lineCount << " - " << line << '\n';
            lineCount++;
        }
        taskFile.close();
    } else {
        std::cout << "File does not exist!";
    }
}