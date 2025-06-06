
// Purpose: program for displaying and manipulating text files.
#include "TextEditorFunc.h"

int main()
{
    while (true)
    {
        string order;
        // Help message
        cout << "\n\n____Welcome To Our Text Editor :)_____ \n1.Add new text to the end of the file.\n2.Display the content of the file."
                "\n3.Empty the file.\n4.Encrypt the file content.\n5.Decrypt the file content\n6.Merge another file\n"
                "7. Count the number of words in the file.\n8. Count the number of characters in the file\n"
                "9. Count the number of lines in the file\n10. Search for a word in the file\n"
                "11. Count the number of times a word exists in the file\n12. Turn the file content to upper case.\n"
                "13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital) \n"
                "15. Save\n16. Exit\n";
        cout << "____________________________________________________________________";
        cout << "\nPlease Choose an Option: \n";
        cin >> order;
        if (order == "1")
        {
            cin.ignore();
            addNewText();
        }
        if (order == "2")
        {
            cin.ignore();
            displayFile();
        }
        if (order == "3")
        {
            cin.ignore();
            emptyFile();
        }
        if (order == "4")
        {
            cin.ignore();
            encryptFile();
        }
        if (order == "5")
        {
            cin.ignore();
            decryptFile();
        }
        if (order == "6")
        {
            cin.ignore();
            mergeFile();
        }
        if (order == "7")
        {
            cin.ignore();
            countWords();
        }
        if (order == "8")
        {
            cin.ignore();
            countCharacters();
        }
        if (order == "9")
        {
            cin.ignore();
            countLines();
        }
        if (order == "10")
        {
            cin.ignore();
            wordSearch();
        }
        if (order == "11")
        {
            cin.ignore();
            countWordFile();
        }
        if (order == "12")
        {
            cin.ignore();
            upperCaseFile();
        }
        if (order == "13")
        {
            cin.ignore();
            lowerCaseFile();
        }
        if (order == "14")
        {
            cin.ignore();
            capitalCaseFile();
        }
        if (order == "15")
        {
            cin.ignore();
            save();
        }
        if (order == "16")
        {
            return 0;

        }
    }

}


