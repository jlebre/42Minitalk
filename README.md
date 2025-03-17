# Minitalk

<p align="center">
  <img src="https://user-images.githubusercontent.com/94384240/171533800-b1fa7318-f18e-44ba-a03f-69bb45900098.jpeg" alt="42 School Logo" width="300">
</p>

## 🛰 42 Cursus - Minitalk

This is the fourth project I coded at 42. The purpose was to code a small data exchange program using UNIX signals.

---

## 📂 Important Files

🔹 To see the `.h` file, [click here](https://github.com/jlebre/42Minitalk/blob/main/minitalk.h)!

🔹 To see the `Makefile`, [click here](https://github.com/jlebre/42Minitalk/blob/main/Makefile)!

🔹 [Server Program](https://github.com/jlebre/42Minitalk/blob/main/server.c)

🔹 [Client Program](https://github.com/jlebre/42Minitalk/blob/main/client.c)

🔹 [Signal Handler](https://github.com/jlebre/42Minitalk/blob/main/signal_handler.c)

🔹 [Utility Functions](https://github.com/jlebre/42Minitalk/blob/main/utils.c)

---

## ⚙️ How to Use

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/jlebre/42Minitalk.git
cd 42Minitalk
```

### 2️⃣ Compile the Programs
```bash
make
```

### 3️⃣ Run the Server
```bash
./server
```
This will start the server and print a Process ID (PID). You will need this PID to send messages.

### 4️⃣ Run the Client to Send Messages
```bash
./client <server_PID> "Your message here"
```
Replace `<server_PID>` with the actual PID printed by the server and "Your message here" with the text you want to send.

### 5️⃣ Expected Behavior
- The server will receive the message character by character via UNIX signals.
- It will then print the received message to the terminal.

---

![minitalk](https://user-images.githubusercontent.com/94384240/190523402-0719914a-cc3d-4919-81c4-f63e6788b078.png)
