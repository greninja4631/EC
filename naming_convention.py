import requests


def fetch_data_from_api(endpoint):
    response = requests.get(endpoint)
    return response.json()


# ダミーの API ではなく、実際の API を指定
api_endpoint = "https://api.github.com"

data = fetch_data_from_api(api_endpoint)
print(data)
