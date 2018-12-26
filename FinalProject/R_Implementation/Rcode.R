library(quantmod)
library(zoo)
# Implementation in R
Data = read.csv(file="/Users/ruohanwu/Desktop/IBM.1min.TradesAndQuotes.20160128.csv", sep=",")
data = data.frame("Time" = Data$TimeBarStart)
data$BidPrice = Data$OpenBidPrice
data$AskPrice = Data$OpenAskPrice
data$Avg = (data$BidPrice + data$AskPrice) / 2
length = print(length(data$Avg))
data$MovingAvg_5[6:length] = rollmean(data$Avg, 6)
data$MovingAvg_20[21:length] = rollmean(data$Avg, 21)
# Signal of 1 means go long and Signal of 0 means go short
signal = array(dim = c(length,1))
signal[,1] = 0
for (i in 21:length){
  ind1 = (data$MovingAvg_5[i] > data$MovingAvg_20[i] 
          & data$MovingAvg_5[i-1] <= data$MovingAvg_20[i-1])
  ind2 = (data$MovingAvg_5[i] < data$MovingAvg_20[i] 
          & data$MovingAvg_5[i-1] >= data$MovingAvg_20[i-1])
  if (!is.na(ind1) & ind1){
    signal[i] = 1
  }
  if (!is.na(ind2) & ind2){
    signal[i] = -1
  } 
}
data$signal = signal
plot(data$MovingAvg_5, type = 'l')
lines(data$MovingAvg_20, col = 'red', type = 'l')
points(which(data$signal == 1),data$BidPrice[which(data$signal == 1)], pch = 19, cex = 0.5, col = 'red')
points(which(data$signal == -1),data$AskPrice[which(data$signal == -1)], pch = 19, cex = 0.5, col = 'green')

print(data$Time[which(data$signal == 1)])
print(data$Time[which(data$signal == -1)])
print(data$Time[which(data$signal == 1 | data$signal == -1)])

# Plot the data we get from C++
MyDataAvg <- read.csv(file="/Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/averagePrice.csv", header=FALSE, sep=",")
nRow = nrow(MyDataAvg)
MyDataOrder <- read.csv(file="/Users/ruohanwu/Desktop/ieorhomework7/cmake-build-debug/output.csv", header=FALSE, sep=",")
BuyRow = (MyDataOrder[,4] == 1)
SellRow = (MyDataOrder[,4] == 0)
BuyOrder = MyDataOrder[BuyRow,]
SellOrder = MyDataOrder[SellRow,]
print(BuyOrder$V1)
print(SellOrder$V1)
plot(MyDataAvg[,1],MyDataAvg[,2],type = 'l',xlab = "Time", ylab = "price")
lines(MyDataAvg[,1],MyDataAvg[,3],type = 'l', col = 'red')
points(BuyOrder[,2],BuyOrder[,3], col = 'red',pch = 19, cex = 0.5)
points(SellOrder[,2],SellOrder[,3], col = 'green',pch = 19, cex = 0.5)

