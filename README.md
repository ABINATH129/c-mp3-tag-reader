# c-mp3-tag-reader
🎵 MP3 Tag Reader & Editor in C

A console-based MP3 Tag Reader and Editor application developed in C that allows users to view and modify ID3 metadata tags of an MP3 file.
This project was built as part of my Embedded Systems learning journey and focuses on binary file handling, command line arguments, and metadata processing in C.

🚀 Project Overview

MP3 files contain ID3 metadata tags that store information about the audio file.
This project reads and edits those tags directly from the binary structure of an MP3 file.

The program can read and modify the following metadata fields:

Title

Artist

Album

Year

Genre

Comment

The system verifies that the file is a valid MP3 file with an ID3 header before reading or modifying the tags.

✅ Key Features

View MP3 metadata tags
Edit specific MP3 tags
Command line argument based execution
MP3 file format validation
ID3 header verification
Safe tag modification using temporary file handling
Modular C program structure

🔍 Tags Supported

🎵 Title (TIT2)
🎤 Artist (TPE1)
💿 Album (TALB)
📅 Year (TYER)
🎼 Genre (TCON)
📝 Comment (COMM)

🛠 Technical Concepts Used

File handling (binary files)
Command line argument processing
Header and source file separation
Dynamic memory allocation
String handling functions
Byte manipulation and parsing
Modular programming

🎯 Learning Outcome

Through this project I improved my skills in:

Binary file processing in C
Understanding MP3 metadata structure
Working with command-line utilities
Memory management and data parsing
Designing modular and maintainable C programs

🔧 Future Improvements (Planned)

Support for additional ID3 tags
Improved error handling
Backup creation before editing files
Interactive menu-based interface
Batch editing for multiple MP3 files

🤝 Feedback

Suggestions and improvements are welcome.
This project is part of my continuous learning journey in C and Embedded Systems.
