from pymongo import MongoClient
client = MongoClient('localhost', 27017)
db = client.dbsparta

## 코딩 할 준비 ##

# 1. 어벤져스: 엔드게임 평점을 찾자!
# 힌트: find( {찾는 조건을 여기다 적으세요} )
movie = db.movie.find_one({'title': '어벤져스: 엔드게임'}, {'_id': False})
print(movie['star'])

avengers = db.movie.find_one({'title':'어벤져스: 엔드게임'},{'_id': False})
print(avengers['star'])

# 2.'어벤져스: 엔드게임'의 평점과 같은 평점의 영화 제목들을 가져오기
# 힌트: find( {찾는 조건을 여기다 적으세요} )

# 1) 엔드게임의 평점
av_star = movie['star']

# 2) 그거랑 같은 영화"들"을 가져오자.
target_movies = list(db.movie.find({'star':av_star}, {'_id': False}))
print(target_movies)

# 3) 그 제목들을 인쇄하자.
for movie in target_movies:
    print(movie['title'])


# 3. '어벤져스: 엔드게임'의 평점과 같은 평점의 영화 제목들의 평점을 0으로 만들기
# 힌트: update( {찾는 조건을 여기다 적으세요}, { '$set': { 변경 조건을 여기에 적으세요 }} )
db.movie.update_many({'star':av_star}, {'$set': {'star': 0}})