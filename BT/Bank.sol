//SPDX-License-Identifier: GPL-3.0
pragma solidity >= 0.8.2 < 0.9.0;
// Write a smart contract on a test network, for Bank account of a customer for
// following operations: Deposit money | Withdraw Money | Show balance

contract Bank{
    mapping(address => uint) public user_account;
    mapping(address => bool) public user_exist;

    function create_account() public payable returns(string memory){
        require(user_exist[msg.sender] == false, "Account already exist");
        user_account[msg.sender] = msg.value;
        user_exist[msg.sender] = true;
        return "Account created successfully";
    }

    function deposite (uint amount) public payable returns(string memory){
        require(user_exist[msg.sender] == true, "Account does not exist");
        require(amount > 0, "Amount should be greater than 0");
        user_account[msg.sender] += amount;
        return "Amount deposited successfully";
    }

    function withdraw (uint amount) public payable returns(string memory){
        require(user_exist[msg.sender] == true, "Account does not exist");
        require(amount >0 , "Amount should be greater than 0");
        user_account[msg.sender] -= amount;
        return "Amount withdrawn successfully";
    }

    function account_balance() public payable returns(uint){
        return user_account[msg.sender];
    }

    function account_exist() public payable returns(bool){
        return user_exist[msg.sender];
    }

}