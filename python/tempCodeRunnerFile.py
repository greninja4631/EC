import functools

def decorator_1(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print("🌟 decorator_1 before")
        result = func(*args, **kwargs)
        print("🌟 decorator_1 after")
        return result
    return wrapper

def decorator_2(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print("🔥 decorator_2 before")
        result = func(*args, **kwargs)
        print("🔥 decorator_2 after")
        return result
    return wrapper

@decorator_1
@decorator_2
def hello():
    print("👋 Hello, world!")

hello()