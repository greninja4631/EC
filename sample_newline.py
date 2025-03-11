# sample_newline.py
class Greeter:
    def greet(self):
        print("Hello, world!")


def farewell():
    print("Goodbye!")


def main():
    greeter = Greeter()
    greeter.greet()
    farewell()


if __name__ == "__main__":
    main()
