#include "Server.cpp"

int main(void)
{
  Server server(9421);
  server.Run(fun);
  return 0;
}
