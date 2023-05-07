# SP_Cetaceans
A stock prediction web application using Monte Carlo Simulation using DPC++ Library for Intel one API Hackathon
## Problem Statement
Problem 2: Parallelizing Monte Carlo Simulation of Financial Derivatives using SYCL
Monte Carlo simulation is a popular technique used in finance to simulate the behavior of financial derivatives, such as options, in order to estimate their fair value and risk exposure. However, Monte Carlo simulation can be computationally expensive and time-consuming, especially for large portfolios or complex models, which limits its practical use. To overcome this challenge, parallel computing techniques can be used to accelerate Monte Carlo simulations and make them more efficient.

## Task:

The aim of this hackathon is to parallelize Monte Carlo simulation of financial derivatives using SYCL/DPC++ Libraries to design and code a simulation model that accurately predicts stock prices using Monte Carlo simulation within a defined timeframe. The project will involve the following tasks:
1. Implementing a Monte Carlo simulation model for financial derivatives using SYCL/DPC++ Libraries
2. Developing a parallel algorithm that can distribute Monte Carlo simulations across multiple devices, such as CPUs and GPUs, using SYCL.
3. Benchmarking the performance of the parallel Monte Carlo simulation against the serial version and assessing the speedup achieved.
4. Optimizing the parallel Monte Carlo simulation for performance and scalability by experimenting with different parameters, such as batch size and number of iterations.
5. Validating the results of the Monte Carlo simulation against analytical solutions and real-world data to ensure accuracy and reliability.

## Our solution
A Monte Carlo simulation applies a selected model (that specifies the  behaviour of an instrument) to a large set of random trials in an attempt to produce a plausible set of possible future outcomes. In regard to simulating stock prices, the most common model is geometric Brownian motion (GBM).
This project is a simple implementation of a stock prediction algorithm using Moving Average strategy. The moving average strategy is something closely related with the Geometric Brownian movement. The process of using this algorithm is as follows:

-> First, we take the close price of any one particular stock or currency pair from day 1 to day 22, then plot one point in the graph. This point is the average of stock      price from day 1 to day 22.

-> Similarly, we take the avergae of day 2 to day 23, day 3 to day 24 and so on upto the minimum requirement of 42 points that is from Day 42 to day 63. These 42 points        together form a line and the difference of 21 points that we take is mandatory for the efficiency of the algorithm. This line is known as EMA [Exponential Moving            Average] and is used to give an accurate average value for the 21 values of stock taken. 

-> Then, we plot another line using points that are average of day 1 to day 4, day 2 to day 5, and so on upto day 60 to day 63 that is a minimum requirement of 60 points.      For this, we use SMA [Simple Moving Average] that can give a perfect value for 3 stock prices taken. 

-> Now, we compare both these lines that are drawn in the graph, if the 2nd line, the SMA with 60 points goes above than the EMA, it shall mean that the buying momentum of    the stock is high and the stock price increases.

-> If the 2nd line, the SMA with 60 points goes below than the EMA, it shall mean that the selling momentum of the stock is high and thus the stock price decreases.

The program takes in a CSV file containing historical stock price data, and then calculates the Moving Averages for the last 3 and 21 days. Based on these averages, the program predicts whether the stock price is likely to go up or down.

## Reference Trade Chart

![Stock_Diagram](https://user-images.githubusercontent.com/111297454/236674642-80906c55-21f1-4e48-98f9-841c466e2e04.png)

## Implementation of Intel Libraries

We have only used Intel's DPC++ Library [One DPL] and had implemented it in Visual Studio Code. 
We didn't use the concept of Machine Learning because arthematic calculations were really efficient for the uncertain domain of stock prediction.
This project was done so as to predict stock prices of companies individually and the concept of MOnte Carlo Simulation helped us as it uses the concept of probability without the random variables and we have implemented the same in our project.
The implementation of Intel's DPC++ Library [Intel One DPL] helped us in the web application accepting large datasets thus making the program efficient. 

I shall explain it... The minimuim requirement for the dataset is 63 rows with the specified columns. However, the maximum rows is not specified. The most accurate prediction shall be for the largest curve. That shall be achieved if the input dataset has many data to draw the curve and we can examine a variety of trend, getting a deeper understanding of the stock price, thus making the prediction more accurate.

## Demo Video

https://user-images.githubusercontent.com/111297454/236674549-fc056b99-5580-487d-9b36-aa66eb57bd4f.mp4

## Getting Started

To get started with this project, clone the repository to your local machine. The program is written in C++ and can be compiled using any C++ compiler.

## Prerequisites

This program requires a C++ compiler to build and run. You can use any C++ compiler of your choice, such as gcc or clang.

## Usage

1.	Download or clone the repository to your local machine.
2.	Open a terminal or command prompt and navigate to the directory containing the program files.
3.	Compile the program using your C++ compiler.
4.	Prepare your input CSV file with historical stock price data and place it in the same directory as the program files.
5.	Run the program by executing the compiled binary file followed by the name of your input CSV file as the argument. For example: ./stock_prediction test.csv
6.	The program will output the predicted direction (UP or DOWN) and the expected target price based on the Moving Average Algorithm.

## To run the program, open a terminal window in the project directory and type the following command:

$ g++ stock_prediction.cpp -o stock_prediction
$ ./stock_prediction

## Program Details
The program reads the input CSV file using the read_csv() function and stores the data in a vector of vectors. The program then calculates the Moving Average of the last 21 days and the last 3 days using the calculate_average() function. It compares the two averages to determine the predicted direction of the stock price.
If the average of the last 3 days is greater than the average of the last 21 days, the program predicts that the stock price will go UP. It then calculates the highest stock price in the last 21 days and outputs the current stock price and the expected target price.
If the average of the last 3 days is less than or equal to the average of the last 21 days, the program predicts that the stock price will go DOWN. It then calculates the lowest stock price in the last 21 days and outputs the current stock price and the expected target price.
We have used HTML and CSS to create the GUI you see in the demo video, Javascript and PHP to connect the web application to the back end file. We have created the live implementation using C++ and the back end for the web application is using Python. 

Note: The JS file and PHP file would not be added in the github repo. Anyone wishes to see it, mail me on rspranesh18@gmail.com.

## Example Input and Output
## Input

![image](https://user-images.githubusercontent.com/111297454/236668950-b5cdfd6f-7fb8-454d-a0f5-00d2fffa4be5.png)

## Output
$ ./stock_prediction:
UP
Current price: 210.23
Expected target: 220.5

In this example, the program predicts that the stock price is likely to go up based on the Moving Averages calculated for the last 3 and 21 days. The current price of the stock is $210.23, and the expected target price is $220.5.
