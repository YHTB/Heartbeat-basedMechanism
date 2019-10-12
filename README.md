# Heartbeat-basedMechanism
Communication based on heartbeat mechanism

## UDP communication library used ：***https://github.com/RobertIndie/moss***

### 基本原理：客户端根据一定的格式发送一个含有对方ID的包并且每隔一段时间就发送一段含有自己的ID的请求,
### 服务端检测到自己维护的表中含有这个ID就回应一个这段数据。
