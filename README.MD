# Eng version
# Basic blockchain functionality without any network

Here is my attemt to create project with basic blockchain functionality and without any network yet. I have been trying to use all features of C++ STD library where needed, such as move semantics or smart pointers.

## Source of ideas

First at all, i have got the basic code structure from 
[this video](https://www.youtube.com/watch?v=2VDQeQfh4Hs&t=769s) and have started add new features.


## Entities description 

Each blockhain has blocks and here is my block structure 

![block](screenshots/block.png)​

---
Entities description

- Transaction
  - Transaction id - id of the transaction
  - Coin number - how many coins will be transferred 
  - Sender - sender
  - Recipient - recipient (pretty easy, isn`t it?)
  - Create time - time when transaction was created
- Block
  - Block id - block id
  - Previous hash - each block has a hash of the previous block to verify its authenticity
  - Current hash - hash of our block
  - Transaction list - has list of transactions
 
---

Next, we will check the transaction pool like in bitcoin's blockchain. It is a place, where unconfirmed transactions are stored.

![transaction pool](screenshots/transact_pool.png)​

---
Entities description

- Transaction pool
  - List of unconfirmed transactions
  - Max number of transactions in pool 

---

## Process explanation

Let`s imagine, i want to send 5 *the_best_coins* to my friend Alex, so i need to create a transaction and write some data. Now it will look like this.

![transaction pool original](screenshots/transaction_orig.png)​
![transaction pool](screenshots/transact_example.png)​

Transaction id and time will be generated automatically.

The next step is to load our transaction to the transaction pool and wait for the pool to fill up.


![load transaction into pool](screenshots/loading_transaction.png)​

When transaction pool is full, it`s time to create a new block and all transaction are moving to it.

![load transaction into block](screenshots/load_into_block.png)​

After that, block hash generation starts and when it ends, block is created and our transaction with Alex is confirmed! Hooray!

![chain example](screenshots/chain_exmpl.png)​

Whait a minute, what is a Genesis block? Oh, it is just the first block in each blockchain. He has no importand data, but, theoreticaly, we can store some fun information like blockchain creator`s first and last names.

Well, in general, it is the main information about work process.

## Technical part

I am using g++ 8.1.0

Comand to compile:
```
g++ transaction.cpp block.cpp blockchain.cpp transactionPool.cpp main.cpp -o <filename>
```