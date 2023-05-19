import requests

api_key = '256590566f631dca205fad48023d2bc9'
city = '沈阳'
url = f'https://restapi.amap.com/v3/weather/weatherInfo?key={api_key}&city={city}&extensions=base'

response = requests.get(url)
data = response.json()['lives'][0]

weather = data['weather']
temperature = data['temperature']
wind_direction = data['winddirection']
wind_power = data['windpower']

print(f'The weather in {city} is {weather} with a temperature of {temperature} Celsius,wind from{wind_direction},power {wind_power}.')
