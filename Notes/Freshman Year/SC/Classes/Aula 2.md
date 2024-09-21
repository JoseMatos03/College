# Aula 2

subject: Computer organization
topics: CPU, I/O Devices, Memory, Pipelining, Words
created: February 23, 2023 1:09 PM

## Computer organisation

Uniprocessor computers follow the **von Neumann architecture**, which includes a CPU, main memory and input/output devices.

![The von Neumann architecture](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled.png)

The von Neumann architecture

The **von Neumann architecture** has been extended in several ways to address some of its limitations, like the implementation of a **system bus** that connects each component.

A **system bus** has three main elements:

- **Data bus:** moves data from the main memory to the CPU registers (and vice versa);
- **Address bus:** holds the address of the currently accessing data bus data.
- **Control bus:** carries the control signals that specify how the information transfer is to take place.

![System bus model](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%201.png)

System bus model

The bus can only be used to write by one device at a time.

---

## CPU

The **central processing unit (CPU)** is responsible for the execution of a program in the main memory. Each instruction directs the CPU to perform some basic task.

The CPU is composed of 3 other distinct components:

![Untitled](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%202.png)

### Registers

Registers contain a small number of high-speed memory registers that are used to store temporary results and status information. They include:

- **Instruction Pointers (IP)**, which indicate the address of the next instruction.
- **Instruction Register (IR)**, which stores the instruction currently being executed.

### Arithmetic Logic Unit (ALU)

The **ALU** is a digital circuit that is responsible for performing arithmetic and logical operations in a computer's CPU, such as:

- Additions
- Subtractions
- Comparisons

### Control Unit

A control unit is a component of a computer's central processing unit (CPU) that manages the flow of data within the CPU and between the CPU and other components of the computer.

---

## Fetch-Decode-Execute cycle

The **control unit** can be seen as a cyclic program that goes through the set of steps to execute the instructions of another program:

1. Fetch instruction from memory → store it in IR.
2. Determine the instruction.
3. Determine the location of the word used by the instruction.
4. Store that word in the CPU register.
5. Execute the instruction on that word with some operation.
6. Refer to the next instruction by changing the IP.

---

## Clock

The **clock** regulates time within the computer. It uses ticks (time unit) to execute operations, and it’s calculated by a clock cycle (time between two ticks).

---

## Main memory

The **main memory** is a component where programs and data are both stored.

It consists of a number of cells that store a piece of information. Each cell has a address, which programs can refer to it.

It’s called ***Random*-Access Memory (RAM)** for it’s ability to take the same time to grab pieces of information at the end of the stack as to grab a piece at the beginning.

### Memory hierarchy

![Untitled](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%203.png)

![Untitled](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%204.png)

---

## Bytes and Words

- The cell is the smallest addressable unit.
- Almost all modern computers use 8-bit (1 byte) cells.
- Bytes are grouped into words (32-bit words or 64-bit words)
- Instructions operate on entire words.

### Little-endian and Big-endian

When storing a multibyte value in a byte-addressable memory, the order of the individual bytes is relevant.

- **Little-endian** stores it’s words from LSB to MSB.
- **Big-endian** stores it’s words from MSB to LSB.

![Untitled](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%205.png)

---

## I/O devices

An **I/O device** is a hardware system that communicates with the computer.

For each device there is a device driver, which the CPU executes to communicate with it.

![Untitled](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%206.png)

![Untitled](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%207.png)

![Untitled](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%208.png)

![Untitled](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%209.png)

---

## Polling

When a given device produces data that needs to be processed, somehow the CPU needs to take some action. A simple solution, which is not very efficient, is for the CPU to keep checking for incoming data over and over. Whenever it detects that data was made available by the device, it processes it. This method is designated as **polling**, since the CPU repeatedly checks the input device to see whether it has any data. Polling is very simple, but very inefficient.

## Interrupts

To avoid this inefficiency, **interrupts** are generally used instead of polling. An interrupt is a signal sent by a device to the CPU to request its attention. The CPU reacts by suspending what it is doing to answer to the interrupt. For this purpose, the CPU saves information about what it is currently doing so that it can return to it afterwards.

**Example:**

Whenever a key is pressed on the keyboard, an interrupt signal is sent to the CPU. The CPU responds by suspending what it is doing, reading the key that was pressed, processing it, and then returning to the task it was performing just before the key was pressed.

---

## Pipelining

With **pipelining**, the process of executing instructions is divided in stages, allowing multiple instructions to be overlapped in execution. Each stage is responsible for a part of the process and all can run in parallel, thus speeding up the process.

![A standard 5-stage pipeline](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%2010.png)

A standard 5-stage pipeline

![The ideal 5-stage pipeline](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%2011.png)

The ideal 5-stage pipeline

### Consequences of pipelining

The maximum theoretical speed up is however very unlikely to occur in practice, because it is difficult to balance the time it takes to complete each stage. All stages must be equally balanced, otherwise the faster stages must wait for the slower ones. 

Additionally, the following three major aspects also negatively affect the theoretical speed up:

- Resource conflicts
- Data dependencies
- Conditional branch statements

**Resource conflicts**

A **resource conflict** greatly affects instruction-level parallelism. This type of conflict occurs whenever two pipeline stages need to simultaneously access the same resource.

![A resource conflict in a 5-stage pipeline](Aula%202%20b1c61d6c61e24cb1a97debab165f7d77/Untitled%2012.png)

A resource conflict in a 5-stage pipeline

**Data dependencies**

A **data dependency** occurs whenever the result of one instruction, not yet available, is also the operand of a subsequent instruction.

There are some solutions to handle these conflicts. Special hardware can be incorporated to detect instructions whose source operands are destinations for instructions further up the pipeline.

**Conditional branch statements**

Problems in the pipeline can also be caused by a **branch instruction** that modifies the normal execution flow of a program. If the conditional branch is taken, the subsequent instructions must not be executed and the pipeline must be emptied.