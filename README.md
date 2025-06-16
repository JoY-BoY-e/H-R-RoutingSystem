# 🏥 H-R-RoutingSystem

**H-R-RoutingSystem** (Healthcare Relief Routing System) is an advanced C++ application designed to efficiently model, manage, and optimize relief routing between hospitals and healthcare units.  
Built with a focus on real-world applicability in healthcare logistics, it helps efficiently plan relief distribution, emergency response, and network analysis.

---

## 🚀 Features

- **Graph-Based Routing Model**
  - Represents hospitals and their connections as a graph for efficient relief distribution.
  - Uses custom MinHeap (priority queue) implementation for optimized route calculations.

- **Dijkstra-like Shortest Path Algorithm**
  - Calculates minimum travel time/routes from a relief unit to multiple hospitals.
  - Updates optimal paths in real-time as network data changes.

- **Data-Driven Input**
  - Reads network and hospital data from an external file (e.g., `Data.txt`).
  - Flexible structure for easy modification or simulation.

- **Rich Output**
  - Prints all hospital nodes, their connections, and computed shortest paths for relief routing.
  - Useful for logistics planners, emergency response coordinators, and healthcare IT demos.

---

## 🧩 How It Works

1. **Define Hospitals and Routes:**  
   Each hospital and the relief unit are nodes; connections (edges) represent travel routes and times.

2. **File-Based Initialization:**  
   The system reads from `Data.txt`, loading the network topology.

3. **Routing Logic:**  
   - Custom **MinHeap** manages the open nodes, tracking the shortest known travel times.
   - The `findTravelTime` function computes and displays optimal relief routes.

4. **Output:**  
   - Prints the hospital network and optimal paths from the relief unit to each hospital.

---

## 🛠️ Usage

1. **Clone & Build**
   ```bash
   git clone https://github.com/JoY-BoY-e/H-R-RoutingSystem.git
   cd H-R-RoutingSystem
   g++ -o hrrs healthcareReliefRoutingSystem.cpp
   ```

2. **Prepare Input**
   - Edit or provide a `Data.txt` file describing the hospital network.

3. **Run**
   ```bash
   ./hrrs
   ```

---

## ✨ Why Use This Project?

- **Educational Value:**  
  Learn about custom priority queues, graph traversal, and shortest path algorithms in C++.

- **Real-World Application:**  
  A great starting point for healthcare logistics, disaster planning, or general network routing systems.

- **Extensible:**  
  Easily adapt the code for other routing or logistics scenarios.

---

## 🤝 Contributions

Ideas for improvement, bug fixes, or new features are welcome!  
Feel free to fork and submit a pull request.

---

## 👤 Author

- **JoY-BoY-e**

---

## ⚖️ License

MIT

> _Optimizing healthcare relief, one route at a time!_ 🚑🗺️
