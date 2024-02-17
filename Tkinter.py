//(As we are using esp32 we need to use MicroPython and Tkinter GUI separtely 
so that we can have a connection betwwen both, python and esp32 arduino code.
//The ESP32 is programmed using MicroPython to control the stepper motor. It listens for HTTP requests to adjust the stepper motor position.
The Python script running on a PC sends HTTP requests to the ESP32 based on user input from the tkinter GUI.
//We just need to replace "http://esp32_ip_address/control" with the actual IP address of your ESP32 device.)
  
import machine
import time

# Define GPIO pins for the stepper motor
STEPPER_PIN_STEP = 16
STEPPER_PIN_DIR = 17

# Initialize GPIO settings
stepper_step = machine.Pin(STEPPER_PIN_STEP, machine.Pin.OUT)
stepper_dir = machine.Pin(STEPPER_PIN_DIR, machine.Pin.OUT)

# Function to move the stepper motor
def move_stepper(direction, steps):
    stepper_dir.value(direction)
    for _ in range(steps):
        stepper_step.on()
        time.sleep(0.005)  # Adjust delay as per motor speed
        stepper_step.off()
        time.sleep(0.005)  # Adjust delay as per motor speed

# Example: Move stepper motor up (clockwise)
move_stepper(1, 200)  # 1 for clockwise direction, 200 steps
 //PYTHON TKINTER GUI 
import tkinter as tk
from tkinter import ttk
import requests

# Function to send control commands to ESP32
def send_command(direction, steps):
    url = "http://esp32_ip_address/control"  # Replace with ESP32 IP address
    params = {"direction": direction, "steps": steps}
    response = requests.get(url, params=params)
    print(response.text)  # Print response from ESP32

# Create tkinter window
root = tk.Tk()
root.title("Stepper Motor Control")

# Function to handle button clicks
def move_up():
    send_command(1, 200)  # Send control command to move stepper motor up (clockwise)

def move_down():
    send_command(0, 200)  # Send control command to move stepper motor down (anti-clockwise)

# Create buttons for moving the stepper motor
btn_up = ttk.Button(root, text="Up", command=move_up)
btn_up.pack()

btn_down = ttk.Button(root, text="Down", command=move_down)
btn_down.pack()

# Run the tkinter event loop
root.mainloop()
