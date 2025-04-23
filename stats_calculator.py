class RideSharingStats:
    def __init__(self, ride_counts):
        self.ride_counts = ride_counts

    def mean(self):
        return sum(self.ride_counts) / len(self.ride_counts)

    def median(self):
        sorted_rides = sorted(self.ride_counts)
        n = len(sorted_rides)
        mid = n // 2
        if n % 2 == 0:
            return (sorted_rides[mid - 1] + sorted_rides[mid]) / 2
        return sorted_rides[mid]

    def mode(self):
        freq = {}
        for ride in self.ride_counts:
            freq[ride] = freq.get(ride, 0) + 1
        max_freq = max(freq.values())
        return [k for k, v in freq.items() if v == max_freq]

if __name__ == "__main__":
    n = int(input("Enter number of drivers: "))
    driver_rides = []
    for i in range(n):
        ride = int(input(f"Enter rides completed by driver {i+1}: "))
        driver_rides.append(ride)

    stats = RideSharingStats(driver_rides)

    print("\nRide Sharing System Statistics")
    print("Average rides per driver (Mean):", round(stats.mean(), 2))
    print("Median rides per driver:", stats.median())
    print("Mode(s):", stats.mode())
