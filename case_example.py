# case_example.py のコード
def calculate_total_price(item_count, price_per_item):
    return item_count * price_per_item


def processData(dataList):
    processed = [data * 2 for data in dataList]
    return processed


item_count = 10
price_per_item = 5.5
total_price = calculate_total_price(item_count, price_per_item)
print(f"Total price is: {total_price}")

dataList = [1, 2, 3, 4]
processed_data = processData(dataList)
print(f"Processed data: {processed_data}")
