#include "CS112-2nd-s1,2,3,4-20210074-20210451-20211035-A4-TextEditorFunc.h"
void addNewText()
{
    string fileName;
    cout << "Please Enter The File Name: ";
    cin >> fileName;
    fstream file;

    // Open the file in Append Mode
    file.open(fileName, ios::app);
    if (file.is_open())
    {
        string lines;
        cout << "Please Enter The Text you'd like to add: ";
        getline(cin >> ws, lines, '\0');
        file << lines << endl;
    }
    else
    {
        cout << "Can not open file!\n Please enter an existing file.";
    }
    file.close();
}
void displayFile()
{
    fstream file;
    char fileName[81];
    cout << "Please Enter An Existing File Name: ";
    cin >> fileName;
    file.open(fileName, ios::in);
    if (file.fail())
    {
        cout << "Failed To Open file!";
    }
    else
    {
        cout << "File Was Opened Successfully!\n"
                "______________________________\n";

        // loops till the end of the file
        while (!file.eof())
        {
            file.getline(fileName, 256, '\n');

            // displaying the file content
            cout << fileName << endl;
        }
        // Close The File
        file.close();
        cout << "____________________________\n";
        cout << "File was Displayed Successfully!";
    }
}
void emptyFile()
{
    ofstream file;
    string fileName;
    cout << "Please enter the name of the file: ";
    cin >> fileName;
    file.open(fileName);
    if (file.is_open())
    {
        // Delete the file content
        file.open(fileName, ios::trunc);
        cout << "__Done__";
        cout << "\n_____";
        file.close();
    }
    else
    {
        cout << "Can not open file!";
    }
}

void encryptFile()
{
    fstream file;
    string fileName;
    cout << "Please Enter An Existing File Name: ";
    cin >> fileName;
    file.open(fileName, ios::in);
    if (file.fail())
    {
        cout << "Failed To Open file!";
    }
    else
    {
        string FileString, encrypted;
        while (!file.eof())
        {
            while (file)
            {
                string line;
                // put every text in the file in string line.
                getline(file, line);
                // put line in FileString.
                FileString += line;
                // put the end line in FileString.
                FileString += '\n';
            }
        }
        // close the file.
        file.close();

        // open the file in out mode.
        file.open(fileName, ios::out);

        // loop over every character in the string FileString.
        for (int i = 0; i < FileString.size(); i++)
        {
            if (FileString[i] == '\n')
            {
                encrypted += '\n';
            }
            else
            {
                // add 1 from every character in the FileString to encrypt it
                char e = FileString[i] + 1;
                encrypted += e;
            }
        }
        file << encrypted << endl;
        cout << "__File was encrypted Successfully!__";
        cout << "\n____________________________";
        // close the file.
        file.close();
    }
}
void decryptFile()
{
    fstream file;
    string fileName;
    cout << "Please Enter An Existing File Name: ";
    cin >> fileName;
    file.open(fileName, ios::in);
    if (file.fail())
    {
        cout << "__Failed To Open file!__";
    }
    else
    {
        string FileString, decrypted;
        while (!file.eof())
        {
            while (file)
            {
                string line;

                // put every text in the file in string line.
                getline(file, line);

                // put line in FileString.
                FileString += line;

                // put the end lines in FileString.
                FileString += '\n';
            }
        }
        // close the file.
        file.close();

        // open the file in out mode.
        file.open(fileName, ios::out);

        // loop over every character in the string FileString.
        for (int i = 0; i < FileString.size(); i++)
        {
            if (FileString[i] == '\n')
            {
                decrypted += '\n';
            }
            else
            {
                // Subtract 1 from every character in the FileString to decrypt it
                char e = FileString[i] - 1;
                decrypted += e;
            }
        }

        // put the encrypted text in the file.
        file << decrypted << endl;

        cout << "__File was decrypted Successfully!__";
        cout << "\n____________________________________";

        // close the file.
        file.close();
    }
}
void mergeFile()
{
    char fileOne[100], fileTwo[100], fileTarget[100], ch;
    fstream fpsOne, fpsTwo, fpTarget;
    cout<<"Enter the Name of First Source File: \n";
    cin>>fileOne;
    cout<<"\nEnter the Name of Second Source File: \n";
    cin>>fileTwo;
    fpsOne.open(fileOne, fstream::in);
    fpsTwo.open(fileTwo, fstream::in);
    if((!fpsOne) || (!fpsTwo))
    {
        cout<<"\nError Occurred (First Source File)!";

    }
    else
    {
        cout<<"\nEnter the Name of Target File: ";
        cin.ignore();
        gets(fileTarget);
        fpTarget.open(fileTarget, fstream::out);
        if(!fpTarget)
            cout<<"\nError Occurred (Target File)!";
        else
        {
            while(fpsOne>>noskipws>>ch)
                fpTarget<<ch;
            fpTarget<<"\n";
            while(fpsTwo>>noskipws>>ch)
                fpTarget<<ch;
            cout<<"\nContent of The Two Files Was Merged Successfully into a Third File!\n";
            cout<<"\n_____________________________________________________________________";
        }
    }
    fpsOne.close();
    fpsTwo.close();
    fpTarget.close();
    cout<<endl;
}


void countWords()
{
    char filename[100], ch, str[1000];
    int total=0, i=0, tot_word=0;
    ifstream fp;
    cout<<"Enter the Name of File: ";
    cin>>filename;
    fp.open(filename, ifstream::in);
    if(!fp)
    {
        cout<<"File doesn't exist or Access denied!"<<endl;

    }
    while(fp>>noskipws>>ch)
    {
        str[total] = ch;
        total++;
    }
    fp.close();
    str[total]='\0';
    while(str[i]!='\0')
    {
        if(str[i]=='\n')
        {
            if(str[i+1]!='\0' && str[i+1]!=' ')
                tot_word++;
            i++;
        }
        else if(str[i]!=' ')
            i++;
        else
        {
            if(str[i+1]!='\0' && str[i+1]!=' ')
                tot_word++;
            i++;
        }
    }
    cout<<endl<<"Total Words = "<<tot_word;
    cout<<endl;

}


void countCharacters()
{
    char filename[100] , ch;
    int tot=0;
    ifstream fp;
    cout<<"Enter the Name of File: ";
    cin>>filename;
    fp.open(filename, ifstream::in);
    if(!fp)
    {
        cout<<endl<<"File doesn't exist or Access denied!";

    }
    while(fp>>noskipws>>ch)
        tot++;
    fp.close();
    cout<<endl<<"Total Characters = "<<tot<<endl;

}

void countLines()
{
    char filename[100] , ch, str[1000];
    int tot=0, i=0, tot_lines=0;
    ifstream fp;
    cout<<"Enter the Name of File: ";
    cin>>filename;
    fp.open(filename, ifstream::in);
    if(!fp)
    {
        cout<<endl<<"File doesn't exist or Access denied!";

    }
    while(fp>>noskipws>>ch)
    {
        str[tot] = ch;
        tot++;
    }
    fp.close();
    str[tot]='\0';
    while(str[i]!='\0')
    {
        if(str[i]=='\n')
            tot_lines++;
        i++;
    }
    tot_lines++;
    cout<<endl<<"Total Number of Lines = "<<tot_lines<<endl;
    cout<<"\n_____________________________\n";

}

void wordsearch()
{
    string input_file,wordToFind,line;
    while (1)
    {
        int line_Number=0,found=0;
        cout<<"\n\nFile: ";
        getline(cin,input_file);
        cout<<"\nWord to find: ";
        getline(cin,wordToFind);
        ifstream file(input_file.c_str());
        if(file)
        {
            while(getline(file,line))
            {
                line_Number++;
                int position=0;
                for(int i=line.find(wordToFind); i<line.length(); i=i+position)
                {
                    position=line.find(wordToFind,i);
                    if(position != string::npos)
                    {
                        cout<<endl<<wordToFind<<" is at "<<line_Number<<":"<<position<<endl;
                        found=1;
                        break;
                    }
                    else
                        break;
                }
            }
            file.close();
            if(found==0)
            {
                cout<<endl<<wordToFind<<" not in file"<<endl;
            }
        }
            else //if file provided is not available.
            {
                cout<<endl<<input_file<<" not found" <<endl;
            }
        _getch();
    }
    return 0;
 }

void countWordFile()
{
    // Initialize Variables
    ifstream file;
    string fileName;
    string word;
    string keyword;
    int count = 0;

    // Ask For File Name
    cout << "Please Enter An Existing File Name: ";
    cin >> fileName;

    // Ask For Word
    cout << "Please Enter the Word: ";
    cin >> keyword;

    // Open The File Or Fail
    file.open(fileName, ios::in);
    if (file.fail())
    {
        cout << "__Failed To Open file!__";
    }
    else
    {
        while (!file.eof())
        {
            file >> word;
            if (word == keyword)
            {
                count++;
            }
        }
        cout << "Number of words in file are: " << count << endl
             << endl;
    }
    file.close();
}


void lowerCaseFile()
{
    // Initialize Variables
    ifstream file;
    string fileName;
    string word;

    // Ask For File Name
    cout << "Please Enter An Existing File Name: ";
    cin >> fileName;

    // Open The File Or Fail
    file.open(fileName, ios::in);
    if (file.fail())
    {
        cout << "__Failed To Open file!__";
    }
    else
    {
        cout << "\n=====================";
        while (!file.eof())
        {
            file >> word;
            cout << word << " ======================> ";
            for (int i = 0; word[i] != '\0'; i++)
            {
                if (word[i] >= 'A' && word[i] <= 'Z') // check for uppercase chars
                    word[i] = word[i] + 32;           // convert uppercase into lowercase
            }
            cout << word;
            cout << endl;
            }
            cout << "=========================\n";
        }
        file.close();
    }

void upperCaseFile()
{
    // Initialize Variables
    ifstream file;
    string fileName;
    string word;

    // Ask For File Name
    cout << "Please Enter An Existing File Name: ";
    cin >> fileName;

    // Open The File Or Fail
    file.open(fileName, ios::in);
    if (file.fail())
    {
        cout << "__Failed To Open file!__";
    }
    else
    {
        while (!file.eof())
        {
            file >> word;
            cout << "\n================BEFORE====================\n";
            cout << word;
            cout << "\n================AFTER====================\n";
            for (int i = 0; word[i] != '\0'; i++)
            {
                if (word[i] >= 'a' && word[i] <= 'z') // check for uppercase chars
                    word[i] = word[i] - 32;           // convert uppercase into lowercase
            }
            cout << word;
            cout << endl;
        }
    }
        file.close();
}

void capitalCaseFile()
{
    // Initialize Variables
    ifstream file;
    string fileName;
    string word;

    // Ask For File Name
    cout << "Please Enter An Existing File Name: ";
    cin >> fileName;

    // Open The File Or Fail
    file.open(fileName, ios::in);
    if (file.fail())
    {
        cout << "__Failed To Open file!__";
    }
    else
    {
        while (!file.eof())
        {
            file >> word;
            cout << "\n================BEFORE====================\n";
            cout << word;
            cout << "\n================AFTER====================\n";
            for (int i = 0; word[i] != '\0'; i++)
            {
                if (i == 0 && word[i] >= 'a' && word[i] <= 'z') // check for uppercase chars
                    word[i] = word[i] - 32;                     // convert uppercase into lowercase
                    if (i != 0 && word[i] >= 'A' && word[i] <= 'Z') // check for uppercase chars
                        word[i] = word[i] + 32;                     // convert uppercase into lowercase
                }
                cout << word;
                cout << endl;
            }
        }
        file.close();
    }
void save()
{
    ifstream currentFile;
    ofstream newFile;
    string currentFileName;
    string newFileName;
    char charcterPlaceholder;

    // Ask For File Name
    cout << "Please Enter An Existing File Name: ";
    cin >> currentFileName;

    // Ask For File Name
    cout << "Please Enter the new File Name: ";
    cin >> newFileName;

    currentFile.open(currentFileName);
    newFile.open(newFileName);

    if (currentFile.fail())
    {
        cout << "__Failed To Open file!__";
    }
<<<<<<< HEAD
    while (!currentFile.eof())
    {
        charcterPlaceholder = currentFile.get();
        cout << endl<< charcterPlaceholder << endl;
        newFile.put(charcterPlaceholder);
    }
    cout << "\nDone\n";
    currentFile.close();
    newFile.close();
=======
    
>>>>>>> 8856e0623a27fbcbeb5a20af6290174a316c1090
}
