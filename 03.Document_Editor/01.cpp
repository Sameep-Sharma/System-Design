#include<bits/stdc++.h>
using namespace std;

//This is a bad design of Document Editor because we are ingesting everything in a single class which violates the SOLID principles. The class is doing too many things and is tightly coupled with the implementation details of the document editing process. It does not follow the Single Responsibility Principle (SRP) and makes it difficult to maintain or extend the code in the future.

class DocumentEditor {
private:
    vector<string>documentElements;
    string renderedDocument;

public:
    //Adds a new element to the document
    void addElement(string text) {
        documentElements.push_back(text);
    }

    void addImage(string imagePath) {
        documentElements.push_back(imagePath);
    }

    //Renders the document by concatenating all elements
    string renderDocument() {
        if(renderedDocument.empty()) {
            string result;
            for(auto& element : documentElements) {
              if(element.size()>4 && (element.substr(element.size()-4) == ".png" || element.substr(element.size()-4) == ".jpg")) {
                  result += "<img src='" + element + "' />";
              } else {
                  result += "<p>" + element + "</p>";
              }  
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }
    
    void saveToFile(){
      ofstream file("document.txt");
      if(file.is_open()) {
          file << renderDocument();
          file.close();
      } else {
          cout << "Unable to open file for writing." << endl;
      } 
    }
};

int main() {
    DocumentEditor editor;
    editor.addElement("This is a sample document.");
    editor.addImage("image1.png");
    editor.addElement("This is another paragraph.");
    editor.addImage("image2.jpg");

    cout << "Rendered Document: " << endl;
    cout << editor.renderDocument() << endl;

    editor.saveToFile();
    return 0;
}