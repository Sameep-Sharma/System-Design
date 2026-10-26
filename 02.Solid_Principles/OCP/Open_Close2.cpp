
#include <bits/stdc++.h>
using namespace std;

// Interface for all payment methods
class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;

    virtual ~PaymentMethod() {}
};

// Credit card payment
class CreditCardPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processing credit card payment of Rs "
             << amount << endl;
    }
};

// PayPal payment
class PayPalPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of Rs "
             << amount << endl;
    }
};

// UPI payment
class UPIPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processing UPI payment of Rs "
             << amount << endl;
    }
};

// Processes any payment method through the interface
class PaymentProcessor {
public:
    void process(PaymentMethod* paymentMethod, double amount) {
        paymentMethod->processPayment(amount);
    }
};

// Checkout service depends on the abstraction
class CheckoutService {
public:
    void processPayment(PaymentMethod* method, double amount) {
        PaymentProcessor processor;
        processor.process(method, amount);
    }
};

int main() {
    CheckoutService checkout;

    CreditCardPayment credit;
    PayPalPayment paypal;
    UPIPayment upi;

    checkout.processPayment(&credit, 100.00);
    checkout.processPayment(&paypal, 100.00);
    checkout.processPayment(&upi, 100.00);

    return 0;
}