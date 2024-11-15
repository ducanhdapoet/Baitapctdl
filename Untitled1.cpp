#include <iostream>
#include <string>

using namespace std;

struct File {
    string name;
    int size;          
    string timestamp;  
    File* next;        
};


struct DriveD {
    File* head;              
    int maxSize;             

   
    DriveD(int maxSize) : head(nullptr), maxSize(maxSize) {}

  
    void addFile(string name, int size, string timestamp) {
        File* newFile = new File{name, size, timestamp, nullptr};

     
        if (head == nullptr || timestamp < head->timestamp) {
            newFile->next = head;
            head = newFile;
        } else {
            File* current = head;
            while (current->next != nullptr && current->next->timestamp < timestamp) {
                current = current->next;
            }
            newFile->next = current->next;
            current->next = newFile;
        }

     
        while (calculateTotalSize() > maxSize) {
            deleteSmallestFile();
        }
    }

   
    int calculateTotalSize() const {
        int totalSize = 0;
        File* current = head;
        while (current != nullptr) {
            totalSize += current->size;
            current = current->next;
        }
        return totalSize;
    }

    
    void deleteSmallestFile() {
        if (head == nullptr) return;

        File* smallestFile = head;
        File* prev = nullptr;
        File* current = head;
        File* prevSmallest = nullptr;

        while (current != nullptr) {
            if (current->size < smallestFile->size) {
                smallestFile = current;
                prevSmallest = prev;
            }
            prev = current;
            current = current->next;
        }

        if (prevSmallest != nullptr) {
            prevSmallest->next = smallestFile->next;
        } else {
            head = head->next;
        }
        delete smallestFile;
    }
    void displayFiles() const {
        File* current = head;
        while (current != nullptr) {
            cout << "File: " << current->name << ", Size: " << current->size
                 << " MB, Timestamp: " << current->timestamp << endl;
            current = current->next;
        }
    }
};

int main() {

    DriveD driveD(32768);

    driveD.addFile("file1.", 1024, "2024-01-01 10:00"); // 1GB
    driveD.addFile("file2", 2048, "2024-01-02 11:00"); // 2GB
    driveD.addFile("file3", 4096, "2024-01-03 12:00"); // 4GB
    driveD.addFile("file4", 512, "2024-01-04 13:00");  // 0.5GB
    driveD.addFile("file5", 8192, "2024-01-05 14:00"); // 8GB

    cout << "Initial list of files:" << endl;
    driveD.displayFiles();

    cout << "\nTotal size of files: " << driveD.calculateTotalSize() << " MB" << endl;


    driveD.addFile("file6.txt", 16384, "2024-01-06 15:00"); 

    cout << "\nList of files after adding file6 (ensuring total size <= 32GB):" << endl;
    driveD.displayFiles();

    return 0;
}