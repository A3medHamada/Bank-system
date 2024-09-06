# Advanced Bank System Console Application

A comprehensive banking system built in C++ using Object-Oriented Programming (OOP) concepts such as inheritance, polymorphism, encapsulation, and abstraction. The system features a console interface for managing users, accounts, and transactions with multiple user roles and permissions.

## Features

- **OOP Principles**:
  - Full use of OOP concepts including classes, inheritance, polymorphism, encapsulation, and abstraction.
  
- **User Management**:
  - Role-based access control (Admin, Employee, Client).
  - User authentication with email and password.

- **Client Management**:
  - Admins can add, modify, delete, and view client information.

- **Account Operations**:
  - Deposit and withdraw funds with secure transaction management.
  - Display client account information.

## Classes and Inheritance

- **Base Class**: `User`
  - Contains common properties like `email`, `password`, and methods for authentication.
  
- **Derived Classes**:
  - `Admin`: Inherits from `User` and has permissions to manage users and clients.
  - `Employee`: Inherits from `User` with permissions to manage clients only.
  - `Client`: Inherits from `User` and manages its own account.

- **Account Class**:
  - Handles account operations such as deposit, withdrawal, and balance checks.

## Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/A3medHamada/Bank-system.git
   ```

2. **Compile the Project**:
   ```bash
   g++ -o bank_system main.cpp user.cpp admin.cpp employee.cpp client.cpp account.cpp bank_system.cpp
   ```

3. **Run the Application**:
   ```bash
   ./bank_system
   ```

## Usage

1. **Login**: Users login with their email and password.
2. **Manage Users and Clients**: Admins and Employees can manage client information.
3. **Account Transactions**: Clients can perform deposits and withdrawals.

## License

This project is open-source and available under the [MIT License](LICENSE).

## Contributing

Feel free to submit issues, fork the repository, and make pull requests for new features or improvement
