
# wxWidgets Hex Editor

This is a little HexEditor that immediatly converts input from Ascii-text to the hexadezimal representation and and vice versa.

## How to complile this project

- Clone this repository to your local machine:

   ```sh
   git clone https://github.com/HTL-Bulme/wx-hex-editor-Izzrina
   ```
- Navigate to to the project-directory

    ```sh
    cd <project folder>
    ```

- To compile the programm use the the `Makefile` and type:

   ```sh
   make
   ```
## Project description

![wireframe](images/hexEditor.svg)

It must be possible to enter text in either of the input
fields. The text immediately appears in both fields - once as regular
ASCII text and once as hex representation of the text.

1.  You can enter any Ascii-Charakter in the text field. 
    The hex-represantation of the whole content of this textCtrl will immediately be shown in the hex-field below. It is possible to clear the input with BACKSPACE, the Linebreaks are represented by the corresponding hexadezimal Value of 0A.

2.  In this field it is only possible to enter hexadecimal values.
    It doesn't matter wether you use uppercase- or lowercase-letters, but every ascii-charakter must be represented by a double-digit.

3.  This button clears both the input and the output in the text fields

4.  With this button you can import any type of file which contains text. Its content will be displayed in the text field and immediately be transformed to the hex-representation shown in the text field below.

4.  With this button you can import any type of file which contains hexadecimal values. Its content will be displayed in the hex field and immediately be transformed to the ascii-text-representation shown in the text field above.

5.  With this button you can write the content of the text field to a file of your choice.

6.  With this button you can write the content of the hex field to a file of your choice.



