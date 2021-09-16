/*
 * Frank Gomes
 * Chapter 3 Labs
 * 21-09-20
 * Extra: JUnit tests
 */

/**
 * Represents a savings account.
 */
public class SavingsAccount {
	private float balance, interest;
	/**
	 * Create new SavingsAccount.
	 * @param bal Starting balance of account.
	 * @param intr Interest rate.
	 */
	public SavingsAccount(float bal, float intr) {
		this.balance = bal;
		this.interest = intr;
	}

	/**
	 * Deposit money into the account.
	 * @param amount Amount to deposit.
	 */
	public void deposit(float amount) {
		this.balance += amount;
	}

	/**
	 * Withdraw money from account.
	 * @param amount Amount to withdraw.
	 */
	public void withdraw(float amount) {
		this.balance -= amount;
	}

	/**
	 * Add interest rate onto account.
	 */
	public void addInterest() {
		this.balance += (this.balance * this.interest) / 100;
	}
}
