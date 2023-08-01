# STM-RTOS
This purpose of this project is to analyze FreeRTOS and visualize it's scheduling of tasks on an STM32.

Tracealyzer is a very useful and interesting tool for debugging and visualizing tasks and schedules of real time systems. Using this tool we will explore and see how FreeRTOS schedules taks and look for behaviors that might not be easily seen. The sections below show the hardware and setup required to complete this project. Tracealyzer is a licensed software with a free 10-day trial. The software has many diagnostics, visualizations, graphs, and features that were not used in this project. Also, Tracealyzer has the ability to stream or view a snapshot of a trace live from the MCU. For this project only snapshots were used since setting up a stream can be complex.

Each branch of the repository is an exploration into different senarios and things tried.

# Hardware and Tools
This project was done using:
* [**STM32F4DISCOVERY**](https://www.st.com/en/evaluation-tools/stm32f4discovery.html).
* [**Tracealyzer**](https://percepio.com/tracealyzer/) by Percepio.
* [**STM32CubeIDE**](https://www.st.com/en/development-tools/stm32cubeide.html)


## Setup
* The onboard programmer ST-LINK needs to be reporgrammed into a J-Link debugger using [these instructions](https://www.segger.com/products/debug-probes/j-link/models/other-j-links/st-link-on-board/).
* Create a project in STM32CubeIDE and add the Tracealyzer libraries and configs. Helpful links below.
  * [Percepio FreeRTOS setup](https://percepio.com/getstarted/latest/html/freertos.html#snapshot-trace)
  * [Tracealyzer for FreeRTOS docs](https://percepio.com/docs/FreeRTOS/manual%20old/)
  * [Percepio YouTube](https://www.youtube.com/watch?v=nw3sEkfbTI0)
* Install Tracealyzer to debugging machine. Signup with e-mail for free 10-day license. [Download](https://percepio.com/tracealyzer/download-tracealyzer/)
* Add Tracealyzer plugin to STM32CubeIDE via Eclipse Marketplace [here](https://marketplace.eclipse.org/content/percepio-trace-exporter-stm32cubeide).
