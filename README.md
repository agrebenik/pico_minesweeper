# Minesweeper for PicoSystem
This project is a remake of windows minesweeper for the PicoSystem handheld [See Here](https://shop.pimoroni.com/products/picosystem)

Documentation for the PicoSystem APIs can be found [Here](https://wiki.picosystem.com/)

Since I did not have access to a PicoSystem at the time of writing to actually test this project on I wrote a C++ library which more or less reflects the expected functionality of a PicoSystem (not all methods are converted but the important ones are). All testing was done with this library after which the code was slightly modified to work with the real PicoSystem APIs. This library mimics the act of drawing to a PicoSystem's screen by generating a bitmap of whatever the screen will render (these will be the imaged you see here).

## Images
Here is how I view the output my code produces. VSCode's ability to update the file live makes playing quite surprisingly easy.

![image](https://github.com/user-attachments/assets/a6da3e83-c076-43a2-8ee5-07c77d668e5f)

User inputs are entered in a console which interfaces with my PicoSystem library and produces the bitmap output. A textual representation of the minefield is present for debugging purposes. 

![image](https://github.com/user-attachments/assets/c59d0208-bc05-48e7-8c8c-bf4c713a6176)

Overall what my testing setup for this game looks like:

![image](https://github.com/user-attachments/assets/a8425c37-0bec-48a0-8960-bf411ee7cbf4)

## Demo Video
Short demo video showcasing the full fuctionality of the minesweeper program as well as PicoAPI interfacing with the console. 

[PicoSystem Minesweeper Demo](https://youtu.be/rOU_spZqSvA)
