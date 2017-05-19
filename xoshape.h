#ifndef XOSHAPE_H
#define XOSHAPE_H

#include <WObject>
#include <WPoint>
#include <WSize>

enum class WPivotPointPosition{
  Center,
  LeftTop,
  LeftBot,
  RightTop,
  RightBot,
  TopJustify,
  BotJustify,
  LeftJustify,
  RightJustify,
};

class XOShape : WObject
{
  WPoint _pivotPonit;
  WPivotPointPosition _pivotType;

  WPoint _leftTopVertex;
  WPoint _rightBotVertex;

  WSize _size;


  void initGiometry();

public:
  XOShape();
  XOShape(WObject parent = nullptr);
  XOShape(WPoint pivotPoint, WSize _size, WPivotPointPosition pivotPointType = WPivotPointPosition::Center);


  void setGiometry(WPoint pivotPoint, WSize size, WPivotPointPosition pivotPointType = WPivotPointPosition::Center);
  void setGiometry(WPivotPointPosition pivotPointType = WPivotPointPosition::Center);

  virtual void draw();
  void draw(WPoint pos);

  WPoint pivotPonit() const;
  void pivotPonit(const WPoint &pivotPonit);

  WPoint leftTopVertex() const;
  WPoint rightBotVertex() const;

  WSize size() const;
  void size(const WSize &size);
};

#endif // XOSHAPE_H
