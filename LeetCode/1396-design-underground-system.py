from typing import Dict, Tuple


class UndergroundSystem:
    def __init__(self):
        # (startStation, endStation): (totolTime, peopleCount)
        self.histories: Dict[Tuple[str, str], Tuple[int, int]] = {}
        # id: (stationName, checkInTime)
        self.checkIns: Dict[int, Tuple[str, int]] = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkIns[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        stationName0, t0 = self.checkIns.pop(id)  # start
        totalT, totalCnt = self.histories.get((stationName0, stationName), (0, 0))
        self.histories[(stationName0, stationName)] = (totalT + t - t0, totalCnt + 1)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        totalT, totalCnt = self.histories[(startStation, endStation)]
        return totalT / totalCnt


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
