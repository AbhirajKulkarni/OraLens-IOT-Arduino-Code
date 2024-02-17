ORALENS IOT 
Abhiraj Kulkarni,BTECH Electronics,
KJ Somiaya College of Engineering,Mumbai
Assignment 3) Objective: Design and program an IoT device for environmental and positional data collection.Tech Stack used: ESP32,Arduino IDE,EasyEDA for circuit Schematic.
We have interfaced all the input and output peripherals to ESP32 to make it IoT enabled.
Here I have used MQ135 AQI sensor to measure the Air Quality accurately. Also Pan And Tilt separate servo motors are interfaced along with sound inputs , stepper motors and the temperature sensor.
All these can be accessed over Wifi remotely as I have connected all these I/O devices to Centralized Blynk Open Cloud platform.  Users can operate it anywhere using the app on their phone. All the motors can be fully controlled using the mobile app and also the data from Temperature and air quality sensor will be accurately seen in the app and website , and as a result we can also keep a record of the data in order to create a database if required for referring the history. We can also customize these automations on the same app itself like if the temperature falls above or below a certain threshold value , we will get instant in app notification and also a centralized email . The same can be done for the MQ135 AQI sensor.
In the advancements we can also integrate Machine Learning algorithms once we get a data setsof our sensor values over a period of time.
In the second part I have integrated the Python Tkinter GUI with up down arrow like icons in order to carry out adjustments of the servo motors which can be done as per requirements.
Also as it is customizable, the device does the work of reposition based on user input for photo captures for a selfie booth.
As ESP32 programming is done in Arduino IDE and TKINTER in python we have to use a separate platform and then enter the same ip address as of esp32 in order to ensure the fully functional working of our device.
I am uploading all the Arduino and Python codes in the GitHub file link.
Schematic Diagram is also uploaded in the folder itself.
I hope as a 3rd year BTech student I am capable of doing the task and work with OraLens in the upcoming months. I would really be very happy to work and serve as a full time Summer Intern at Oralens. Also the healthcare sector drives me more and motivates me to work on such incredible innovations.
