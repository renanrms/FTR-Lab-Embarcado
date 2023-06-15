#include "FTRLab.hpp"

#include "sensors/HallEffectSensor.cpp"

Preferences ftrlabPreferences;

/**
 * Pinos GPIO utilizados no dispositivo.
 * Configure-os de acordo com a necessidade, observando pinos obrigatórios e restrições de hardware para os pinos escolhidos em cada função.
 */
enum DEVICE_PINS
{
  NETWORK_RECONFIGURATION_BUTTON = 5,
  NETWORK_STATUS_LED = 18,
  // Adicione aqui outros pinos utilizados pela placa
};

void setup()
{
  // Configuração de sensores, informações e pinos escolhidos para o dispositivo
  board.setName("Física Básica");
  board.addSensor(new HallEffectSensor());
  board.setDevicePins(
      DEVICE_PINS::NETWORK_RECONFIGURATION_BUTTON,
      DEVICE_PINS::NETWORK_STATUS_LED);

  // Setup do dispositivo (não alterar)
  ftrlabPreferences.begin("FRTLab");
  board.setPreferencesStore(&ftrlabPreferences);
  board.setup();
}

void loop()
{
  // A linha abaixo deve ser chamada a cada iteração do loop
  board.loop();
}
