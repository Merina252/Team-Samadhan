import streamlit as st
from serial import SerialException
import serial 
import subprocess
import os 
import pandas as pd
import numpy as np

with open('style.css') as f:
    st.markdown(f'<style>{f.read()}</style>', unsafe_allow_html=True)

    

st.sidebar.image("logo.png")
st.sidebar.subheader("Mathy")

#UNCOMMENT TO PUT INSTRUCTIONS TO USE MATHY WEB APP


# with st.expander("Learn how to use Mathy"):
#     st.write("""### How to use:

# - Turn on the """)
   
#     st.write("""
# - Select the available COM port and Baud Rate (9600 by default).
# - Record your data by clicking on the "Read your data" button. Wait for 5 seconds while your numbers is being recorded.
# """)
 



col1, col2,col3 = st.columns([1,2,1])
with col1:
    st.subheader("❓Question :")
    st.subheader("✅ Answer :")

with col2:
    st.subheader ("{0} x {1}".format(7,9))
    st.subheader ("{0}".format(63))

col3.image("math.png")

"""
    -------
    """


col1,col2,col3 =st.columns(3)
col1.metric("Total Attempts","5")
col2.metric("Correct Answers","3")
col3.metric("Incorrect Answers","2")





"""
    -------
    """

proc = subprocess.Popen(
    "python -m serial.tools.list_ports -q",
    shell=True,
    stdout=subprocess.PIPE
    )
output = proc.communicate()[0]
output = output.decode("utf-8")
active_ports = [x.strip() for x in output.split(os.linesep)]

st.sidebar.markdown("Mathy is a simple math and memory quiz game. It approaches the children to learn maths in a more fun way. Parents can monitor their children's activity using this simple web app.")

#UNCOMMENT TO ADD SERIAL MONITORING IN MATHY WEB APP


# """ """ """ """ """ """ st.sidebar.write("""### *Select Port*""")
# selected_port = st.sidebar.selectbox(
#     '',
#     active_ports,
#     index=0)
# st.sidebar.write("""### *Select Baudrate*""")

# selected_baudrate = st.sidebar.selectbox(
#     '',
#     (4800, 9600, 19200, 38400, 57600, 115200),
#     index=1
# )
# ser = serial.Serial()
# ser.baudrate = selected_baudrate
# ser.port = selected_port
# """ #### *Connecting to your COM port...*"""
# try:
#     ser.open()
#     st.write("COM port connected successfully.")
#     """
#     -------
#     """

# except SerialException as e:
#     st.write(f"Could not open COM port. Unplug and try again")
#     st.button("Try again")
#     """
#     -------
#     """
#     pass """ """ """ """ """ """

hide_menu_style = """
        <style>
        #MainMenu {visibility: hidden; }
        footer {visibility: hidden;}
        header {visibility: hidden;}
        </style>
        """
st.markdown(hide_menu_style, unsafe_allow_html=True)

"""### *Previous Data*"""
df = pd.DataFrame(
   np.random.randn(3, 3),
   columns=('col %d' % i for i in range(3)))

st.table(df)


#UNCOMMENT TO PUT ADDITIONAL INSTRUCTIONS IN WEBAPP


# st.write("""
# Connect the device into one of the USB port of your laptop or connect it to the same wifi.
# Click on button below once you are ready to start!

# """.strip())

#UNCOMMENT TO USE IT THROUGH USB SERIAL MONITORING

# st.write("Using port: " + ser.port) 
# while True:
#     line = ser.readline()
#     finalValue = line.decode('utf-8').replace('\r','').replace('\n','')
#     st.write(finalValue)