from pymongo import MongoClient           # pymongo를 임포트 하기(패키지 인스톨 먼저 해야겠죠?)
client = MongoClient('localhost', 27017)  # mongoDB는 27017 포트로 돌아갑니다.
db = client.dbsparta                      # 'dbsparta'라는 이름의 db를 만듭니다.

# MongoDB에 insert 하기

# 'users'라는 collection에 {'name':'bobby','age':21}를 넣습니다.
db.users.insert_one({'name':'bobby','age':21})
db.users.insert_one({'name':'kay','age':27})
db.users.insert_one({'name':'john','age':30})

#find({찾는조건},{제외할 녀석들})
#update_many({},{})

all_users = list(db.users.find({'name':'bobby'},{'_id':False}))
for user in all_users:
    print(user)

user = db.users.find_one({'name':'bobby'})
print (user)

# 그 중 특정 키 값을 빼고 보기
user = db.users.find_one({'name':'bobby'},{'_id':0})
print (user)

db.users.update_many({'age':27},{'$set':{'age':30}})

all_users = list(db.users.find({}, {'_id': False}))
for user in all_users:
    print(user)