# 🧠 Minitalk

A simple communication program between a client and a server using **UNIX signals**.  
This project was developed as part of the 42 School curriculum to explore low-level inter-process communication.

---

## 📚 Project Overview

**Minitalk** consists of two programs:

- `server`: Receives and displays messages sent by the client.
- `client`: Sends a string to the server using UNIX signals.

Communication between both programs is achieved using **only** `SIGUSR1` and `SIGUSR2`.

---

## 🚀 How It Works

1. **Start the server**: It will display its PID.
2. **Run the client**: Provide the server PID and the string to send.
3. The client encodes each character bit-by-bit and sends it using signals.
4. The server decodes the signal stream and prints the received message.
